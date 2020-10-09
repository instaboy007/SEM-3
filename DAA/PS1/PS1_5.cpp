#include<iostream>
#include "BST.h"
using namespace std;

int main()
{
    BST *Node=NULL;
    int n=0,x;
    cout<<"\nENTER THE NUMBER OF ELEMENTS:";
    cin>>n;
    cout<<"\nENTER THE ELEMENTS:";
    for(int i=0;i<n;i++)
    {
        cin>>x;
        Node=insert(Node,x);
    }
    cout<<"\n";
    print(Node);
    cout<<"\n ENTER THE VALUE OF X:";
    cin>>x;
    n=numberofnodes(Node);
    if(n==x)
    {
        cout<<"\nGOOD!\n";
    }
    else if(n>x)
    {
        cout<<"\nAVERAGE\n";
    }
    else if(n<x)
    {
        cout<<"\nBAD\n";
    }
}