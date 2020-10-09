#include<iostream>
#include "BST.h"
using namespace std;

int main()
{
    BST *Node=NULL;
    int n=0,m=0,temp=0;
    cout<<"\nENTER THE NUMBER OF STUDENTS IN THE CLASS:";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cout<<"\nENTER THE NUMBER OF CANDIES WITH THE "<<i+1<<" STUDENT :";
        cin>>temp;
        Node=insert(Node,temp);
    }
    cout<<"\nTREE\n";
    print(Node);
    cout<<"\nENTER THE NUMBER OF STUDENTS WHO ARE YET TO COME:";
    cin>>m;
    BST *copy;
    for(int i=0;i<m;i++)
    {
        cout<<"\nENTER THE NUMBER OF CANDIES WITH THE "<<i+1<<" STUDENT :";
        cin>>temp;
        copy=search(Node,temp);
        if(copy->key==temp)
        {
            cout<<"\nMONK :YES!!!";
        }
        else
        cout<<"\nMONK :NO!!!";
    }
}