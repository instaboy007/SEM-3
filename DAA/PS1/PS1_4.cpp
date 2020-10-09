#include<iostream>
#include "BST.h"
using namespace std;

int main()
{
    int choice;
    BST *root=NULL;
    do
    {
        cout<<"\n1.)INSERT\n2.)TRAVERSE IN LEVEL ORDER\n3.)DISPLAY\n4.)EXIT\nENTER YOUR CHOICE==>";
        cin>>choice;
        switch(choice)
        {
            case 1:
                int key;
                cout<<"\nENTER THE KEY:";
                cin>>key;
                root=insert(root,key);
                break;
            case 2:
                printalllevels(root);
                break;
            case 3:
                if(root==NULL)
                {
                    cout<<"\nTREE EMPTY!";
                }
                print(root);
                break;
        }
    }while(choice<=3);
}