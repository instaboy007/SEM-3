#include<iostream>
using namespace std;

int merge(int a[],int temp[],int left,int mid,int right)
{
    int i,j,k,count=0;
    i=left;//index for left subarray
    j=mid;//index for right subarray
    k=left;//index for merged array
    while((i<=mid-1)&&(j<=right))
    {
        if(a[i]<=a[j])
        {
            temp[k++]=a[i++];
        }
        else
        {
            temp[k++]=a[j++];
            count=count+(mid-i);
        } 
    }
    while(i<=mid-1)
    {
        temp[k++]=a[i++];
    }
    while(j<=right)
    {
        temp[k++]=a[j++];
    }
    for(int i=left;i<=right;i++)
    {
        a[i]=temp[i];
    }
    return count;
}

int mergesort(int a[],int temp[],int left,int right)
{
    int mid,count=0;
    if(left<right)
    {
        mid=(left+right)/2;
        //dividing starts here 
        count+=mergesort(a,temp,left,mid);//count of left subarray
        count+=mergesort(a,temp,mid+1,right);//count of right subarray
        count+=merge(a,temp,left,mid+1,right);//merge left and right subarrays and find count
    }
    return count;
}

int findinv(int a[],int n)
{
    int temp[n];
    return mergesort(a,temp,0,n-1);
}

int main()
{
    int n;
    cout<<"\nENTER THE NUMBER OF ELEMENTS IN THE ARRAY:";
    cin>>n;
    int a[n];
    cout<<"\nENTER THE ELEMENTS OF THE ARRAY :";
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int count;
    count=findinv(a,n);
    cout<<"\nTHE NUMBER OF INVERSIONS IS "<<count<<"\n";
}