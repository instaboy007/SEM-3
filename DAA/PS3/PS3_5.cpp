
#include <iostream>
#include <cmath>
#include <limits.h>

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


int findMinWidth(int colors[], int start, int minWidth, int size)
{
    int width = colors[start + 2] - colors[start];
    if (start + 2 == size)
        return minWidth;
    if (width == 2)
        return 2;
    if (width < minWidth)
        minWidth = width;
    return findMinWidth(colors, start + 1, minWidth, size);
}

int main()
{
    int test_cases;
    cout<<"\nENTER THE NUMBER OF TEST CASES:";
    cin >> test_cases;
    while (test_cases--)
    {
        int cost, n, index = 0;
        cout<<"\nENTER THE VALUE OF N:";
        cin >> n;
        cout<<"\nENTER THE COST M:";
        cin >> cost;
        int arr[n];
        cout<<"\nENTER THE VALUES OF N:";
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        int temp[n];
        mergesort(arr,temp, 0, n-1);

        // Not considering Fractional parts
        int minWidth = findMinWidth(temp, 0, INT_MAX, n);
        int minimumCost = 2 * cost * minWidth * (temp[n - 1] - temp[0]);
        cout << minimumCost << endl;

        // Considering Fractional parts
        double sum = 0.0;
        sum = (temp[n - 1] - temp[1] + temp[n - 2] - temp[0]) * 2.0;
        sum = sum + sqrt(2.0) * (temp[n - 1] - temp[n - 2] + temp[1] - temp[0]);
        long long rounded = ceil(sum);
        cout << rounded * cost << endl;
    }
}