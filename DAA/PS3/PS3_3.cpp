#include<iostream>
using namespace std;
int findSpecial(int sequence[], int start, int end, int k, int index)
{
    if (end-start+1< k)
        return 0;
    if (end-start+1== k)
    {
        bool flag = true;
        for (unsigned i = start; i <= end; i++)
        {
            if (sequence[i]< sequence[index])
            {
                flag=false;
                break;
            }
        }
        if (flag)
            return sequence[index];
        else
            return 0;
    }
    return findSpecial(sequence, start, end - 1, k, index) || findSpecial(sequence, start + 1, end, k, index);
}

int wrapper(int sequence[],int n, int k)
{
    int sum = 0;
    for (unsigned i = 0; i<n; i++)
    {
        if (findSpecial(sequence,0,i-1,k,i) || findSpecial(sequence,i + 1,n-1,k,i))
            sum += sequence[i];
    }
    return sum;
}

int main()
{
    int n;
    int val;
    int k;
    cout <<"\nENTER THE NUMBER OF ELEMENTS IN THE ARRAY:";
    cin>>n;
    int sequence[n];
    cout<<"\nENTER THE ELEMENTS OF THE SEQUENCE :";
    for(int i=0;i<n;i++)
    {
        cin>>sequence[i];
    }
    cout <<"\nENTER THE VALUE OF K:";
    cin >> k;
    cout << "SPECIALITY OF THE SEQUENCE :" << wrapper(sequence,n,k)<< endl;
}