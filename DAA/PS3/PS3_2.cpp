#include<iostream>
using namespace std;

int dividedby5(unsigned int num)
{
    return(num % 5 == 0)? 1 + dividedby5(num/5):0;
}

int minimumNumber(int present, int sum, int value)
{
    if(sum >= value)
        return present-1;
    else
    {
        sum += dividedby5(present);
        return minimumNumber(present+1, sum, value);
    }
}

int main()
{
    int N;
    cout << "ENTER THE VALUE:";
    cin >>N;
    cout << "ANSWER: " <<minimumNumber(1, 0,N)<<endl;
}