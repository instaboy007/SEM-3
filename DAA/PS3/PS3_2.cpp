#include<iostream>
using namespace std;

unsigned int Log5n(unsigned int n) 
{
    if(n < 5)
        return 0;
    return (n > 1) ? 1 + Log5n(n / 5) : 0; 
} 

int minimumNumber(int present, int sum, int value)
{
    if(sum >= value)
        return present-1;
    else
    {
        sum += Log5n(present);
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