#include<iostream>
#include "BST.h"
using namespace std;

int main()
{
    BST *root=NULL;
    int count=0,key=1;
    while(key<11)
    {
        root=insert(root,key);
        key++;
    }
    print(root);
    searchval(root,10,&count);
    cout<<"\n THE NUMBER OF  SEARCHES TO FIND 10 :"<<count<<"\n";
}