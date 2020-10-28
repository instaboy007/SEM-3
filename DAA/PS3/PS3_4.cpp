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
}

int mergesort(int a[],int temp[],int left,int right)
{
    int mid,count=0;
    if(left<right)
    {
        mid=(left+right)/2;
        //dividing starts here 
        mergesort(a,temp,left,mid);//count of left subarray
        mergesort(a,temp,mid+1,right);//count of right subarray
        merge(a,temp,left,mid+1,right);//merge left and right subarrays 
    }
}

int binarySearch(int arr[], int l, int r, int val) 
{ 
    if (r >= l)
    { 
        int mid = l + (r - l) / 2; 
  
        if (arr[mid] == val) 
            return mid; 
  
        if (arr[mid] > val) 
            return binarySearch(arr, l, mid - 1, val); 
  
        return binarySearch(arr, mid + 1, r, val); 
    } 
    return -1; 
} 

int filter(int arr[], int size, int x)
 {
    int available = binarySearch(arr, 0, size, x+1);
    if(available == -1)
        return x+1;
    while(available != -1)
        available = binarySearch(arr, 0, size, ++x);
    return x;
}

int main()
{
    int n;
    cout<<"\nENTER THE SIZE OF ARRAY:";
    cin>>n;
    int a[n];
    cout<<"\nENTER THE VALUYES OF THE ARRAY:";
    for(int i=0;i<n;i++)
    {   
        cin>>a[i];
    }
    int temp[n];
    mergesort(a,temp,0,n-1);
    int x;
    cout<<"\nENTERTHE VALUE OF X:";
    cin>>x;
    cout<<"\nSORTED ARRAY:";
    for(int i=0;i<n;i++)
    {
        cout<<temp[i]<<" ";
    }
    cout<<"\n";
    x=filter(temp,n,x);
    cout<<"\nANSWER :"<<x;
}