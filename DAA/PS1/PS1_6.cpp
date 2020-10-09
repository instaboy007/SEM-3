#include<iostream>
#include<unistd.h>
#include "BST.h"
using namespace std;

int main()
{
    BST *Node=NULL;
    int n;
    cout<<"\nENTER THE NUMBER OF ELEMENTS IN THE ARRAY :";
    cin>>n;
    int a[n];
    cout<<"\nENTER THE ELEMENTS :";
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sleep(2);
    cout<<"\nARRAY AND TREE STARTS CONVERSATION......\n";
    sleep(2);
    cout<<"\nARRAY:HEY TREE! IM BETTER THAN YOU!!;)....\n";
    sleep(2);
    cout<<"\nTREE:WHAT !!! :( IM FRUSTRATED!.....\n";
    sleep(2);
    cout<<"\nTREE STARTS TO CONVERT ARRAY INTO TREE ;)....";
    sleep(2);
    for(int i=0;i<n;i++)
    {
        Node=insert(Node,a[i]);
    }
    cout<<"\nARRAY BECOMES TREE!!!....\n";
    sleep(2);
    print(Node);
    sleep(2);
    cout<<"\nMONK: HEY I WAS WATCHING YOU BOTH FIGHTING....\n";
    sleep(2);
    cout<<"\nMONK: I JUST WANTED TO KNOW THE HEIGHT OF THE TREE! HELP ME...\n";
    sleep(2);
    cout<<"\nME: I WILL HELP YOU!\n";
    sleep(2);
    cout<<"\nTHE HEIGHT OF THE TREE IS "<<height(Node)<<" !!! \n";
    sleep(2);
    cout<<"\nMONK:THANK YOU :)\n";
    sleep(2);
} 