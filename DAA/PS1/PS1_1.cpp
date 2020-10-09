#include<iostream>
#include "BST.h"
using namespace std;

int main()
{
    int choice;
    BST *root=NULL;
    do
    {
        cout<<"\n1.)INSERT\n2.)DELETE MIN\n3.)FIND\n4.)FIND MAX\n5.)FIND LEFT CHILD\n6.)FIND RIGHT CHILD\n7.)INORDER\n8.)PREORDER\n9.)POSTORDER\n10.)DISPLAY\n11.)EXIT\nENTER YOUR CHOICE==>";
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
                if(root==NULL)
                {
                    cout<<"\nTREE EMPTY!";
                    break;
                }
                root=deletenode(root,findmin(root)->key);
                break;
            case 3:
                int tkey;
                cout<<"\nENTER THE KEY TO SEARCH:";
                cin>>tkey;
                if(root==NULL)
                {
                    cout<<"\nTREE EMPTY!";
                }
                BST *find;
                find=search(root,tkey);
                if(find->key==tkey)
                {
                    cout<<tkey<<" IS PRESENT!\n";
                }
                break;
            case 4:
                if(root==NULL)
                {
                    cout<<"\nTREE EMPTY";
                }
                cout<<"\nTHE MAMIMUM VALUE IS : "<<(findmax(root)->key);
                break;
            case 5:
                cout<<"\nENTER THE KEY:";
                cin>>key;
                if(root==NULL)
                {
                    cout<<"\nTREE EMPTY";
                }
                find=search(root,key);
                if(find->left!=NULL)
                {
                    cout<<"\nTHE LEFT CHILD OF "<<key<<" IS "<<find->left->key<<"\n";
                }
                else
                {
                    cout<<"\nLEFT CHILD IS NULL!";
                }
                break;
            case 6:
                cout<<"\nENTER THE KEY:";
                cin>>key;
                if(root==NULL)
                {
                    cout<<"\nTREE EMPTY";
                }
                find=search(root,key);
                if(find->right!=NULL)
                {
                    cout<<"\nTHE RIGHT CHILD OF "<<key<<" IS "<<find->right->key<<"\n";
                }
                else
                {
                    cout<<"\nRIGHT CHILD IS NULL!";
                }
                break;
            case 7:
                if(root==NULL)
                {
                    cout<<"\nTREE EMPTY!";
                }
                inorder(root);
                break;
            case 8:
                if(root==NULL)
                {
                    cout<<"\nTREE EMPTY!";
                }
                preorder(root);
                break;
            case 9:
                if(root==NULL)
                {
                    cout<<"\nTREE EMPTY!";
                }
                postorder(root);
                break;
            case 10:
                if(root==NULL)
                {
                    cout<<"\nTREE EMPTY";
                }
                print(root);
                break;
        }
    }while(choice<11);
}
