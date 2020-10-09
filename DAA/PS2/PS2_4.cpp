#include<iostream>
#include "AVL.h"
using namespace std;

void change(AVL *&root1,AVL *&root2)
{
    if(root1 != NULL)
    {
        if(root2 != NULL)
        {
            while(root1->key!= root2->key)
            {
                if(root1->key > root2->key)
                {
                    if(root1->left != NULL && root1->left->right != NULL && root1->left->right->key == root2->key)
                    {
                        root1->left = RR(root1->left);
                        root1 = LL(root1);
                        cout << "LR rotation" << endl;
                    }
                    if(root1->right != NULL || root1->left != NULL)
                    {
                        root1 = LL(root1);
                        cout << "LL rotation" << endl;
                    }
                }
                if(root1->key < root2->key)
                {
                    if(root1->right != NULL && root1->right->left != NULL && root1->right->left->key == root2->key)
                    {
                        root1->right = LL(root1->right);
                        root1 = RR(root1);
                        cout << "RL rotation" << endl;
                    }
                    if(root1->right != NULL || root1->left != NULL)
                    {
                        root1 = RR(root1);
                        cout << "RR rotation" << endl;
                    }
                    
                }
            }
            change(root1->left, root2->left);
            change(root1->right, root2->right);
        }
    }
}   

int main()
{
    AVL *root1=NULL,*root2=NULL;
    int n,key;
    cout<<"\n ENTER THE NUMBER OF NODES IN THE TREE:";
    cin>>n;
    cout<<"\nENTER THE ELEMENTS OF THE FIRST TREE:";
    for(int i=0;i<n;i++)
    {
        cin>>key;
        root1=insert(root1,key);
    }
    cout<<"\nTREE 1"<<endl;
    print(root1);
    cout<<endl;
    cout<<"\nENTER THE ELEMENTS OF THE SECOND TREE:";
    for(int i=0;i<n;i++)
    {
        cin>>key;
        root2=insert(root2,key);
    }
    cout<<"\nTREE 2:"<<endl;
    print(root2);
    cout<<endl;
    change(root1,root2);
    cout<<"CHANGED TREE 1:"<<endl;
    print(root1);
    cout<<"\nTREE 2:"<<endl;
    print(root2);
}