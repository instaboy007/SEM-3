#include<iostream>
#include "AVL.h"
using namespace std;

int main()
{
    int choice;
    AVL *root=NULL;
    do
    {
        cout<<"\n1.)INSERT\n2.)DISPLAY\n3.)EXIT\nENTER YOUR CHOICE==>";
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
                print(root);
                break;
        }
    }while(choice<3);
}