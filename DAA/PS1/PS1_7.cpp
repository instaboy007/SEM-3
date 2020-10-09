#include<iostream>
#include<bits/stdc++.h> 
using namespace std;

void inorder(int a[],std::vector<int> &v,int n,int index)
{
    if(index>=n)
        return;
    inorder(a,v,n,2*index+1);
    v.push_back(a[index]);
    cout<<a[index];
    inorder(a,v,n,2*index+2);
}

int minswap(std::vector<int> &v)
{
    std::vector<pair<int,int>> t(v.size());
    int ans = 0; 
    for(int i = 0; i < v.size(); i++)
    { 
        t[i].first = v[i], t[i].second = i; 
    } 
    sort(t.begin(), t.end()); 
    for(int i = 0; i < t.size(); i++) 
    { 
        // second element is equal to i 
        if(i == t[i].second) 
            continue; 
        else
        { 
            // swaping of elements 
            swap(t[i].first, t[t[i].second].first); 
            swap(t[i].second, t[t[i].second].second); 
        } 
          
        // Second is not equal to i 
        if(i != t[i].second) 
            --i; 
        ans++; 
    } 
    return ans; 
} 

int main()
{
    int n;
    cout<<"\nENTER THE NUMBER OF ELEMENTS IN THE BINARY TREE :";
    cin>>n;
    int a[n];
    cout<<"\nENTER THE ELEMENTS OF THE BINARY TREE :";
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    std::vector<int> v;
    inorder(a,v,n,0);
    cout<<minswap(v)<<"IS THE NUMBER OF SWAPS!\n";
}