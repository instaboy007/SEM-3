sequalize.query('CREATE  TRIGGER PercentageCalc BEFORE INSERT ON attendances'+ 
'FOR EACH ROW'+
'SET NEW.Percentage =(NEW.PeriodNo/NEW.TotalPeriodNo)*100;')

