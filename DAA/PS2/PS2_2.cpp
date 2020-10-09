#include<iostream>
#include "AVL.h"
using namespace std;

int main()
{
    int choice;
    AVL *root=NULL;
    do
    {
        cout<<"\n1.)INSERT\n2.)DELETEMIN\n3.)DELETE NODE WITH LEFT CHILD\n4.)DELETE ROOT\n5.)FIND\n6.)INORDER\n7.)FIND HEIGHT\n8.)KEY BETWEEN A & B\n9.)NUMBER OF LEAVES\n10.)DISPLAY\n11.)EXIT\nENTER YOUR CHOICE==>";
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
                root=deletenode(root,findmin(root)->key);
                break;
            case 3:
                root=deletenode(nodeleftchild(root),nodeleftchild(root)->key);
                break;
            case 4:
                root=deletenode(root,root->key);
                break;
            case 5:
                cout<<"\nENTER THE KEY TO SEARCH: ";
                cin>>key;
                if(searchkey(root,key)->key==key)
                {
                    cout<<"THE KEY "<<key<<" IS PRESENT!\n";
                }
                break;
            case 6:
                inorder(root);
                break;
            case 7:
                cout<<"THE HEIGHT OF THE TREE IS "<<height(root)<<"\n";
                break;
            case 8:
                int a,b;
                cout<<"\nENTER THE VALUES OF A:";
                cin>>a;
                cout<<"\nENTER THE VALUES OF B:";
                cin>>b;
                searchbetween(root,a,b);
                break;
            case 9:
                cout<<"\nTHE NUMBER OF LEAF NODES IS "<<findleaf(root)<<"\n";
                break;
            case 10:
                print(root);
                break;
        }
    }while(choice<11);
}