const row=sequalize.query('CREATE  TRIGGER PercentageCalc BEFORE INSERT ON attendances'+ 
'FOR EACH ROW'+
'SET NEW.Percentage =(NEW.PeriodNo/NEW.TotalPeriodNo)*100;')

const row=sequalize.query('CREATE TRIGGER findavg BEFORE INSERT ON TMarks'+
'FOR EACH ROW'+
'SET NEW.CA =(NEW.CA1_Mark/2 + NEW.CA2_Mark/2);')

const row=sequalize.query('CREATE TRIGGER findtotal BEFORE INSERT ON TMarks'+
'FOR EACH ROW'+
'SET NEW.Total =(NEW.CA+ NEW.Assignment_Mark + NEW.Tutorial_Mark);')

const row=sequalize.query('CREATE TRIGGER findltotal BEFORE INSERT ON LMarks'+
'FOR EACH ROW'+
'SET NEW.Total =(NEW.Lab1_Mark + NEW.Lab2_Mark + NEW.LabFinal_Mark + NEW.Package_Mark);')

delimiter $$
CREATE PROCEDURE cgpa1(studentid VARCHAR(6)) 
BEGIN
SELECT StudentId,TRUNCATE(SUM(credit*Gradepoint)/SUM(credit),2) AS cgpa,Result FORM semresults WHERE StudentId=studentid;
END $$
delimiter ;

const row = await sequelize.query('call cgpa1();').spread(
    function (req.params.id) {
});
