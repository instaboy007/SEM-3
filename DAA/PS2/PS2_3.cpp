#include<iostream>
#include "D:\My Files\SEM III\Design & Analayis of Algorithm\Lab\BST-WS1\BST.h"
using namespace std;

BST * newNode(int val)  
{  
    BST* node = new BST; 
    node->key = val;  
    node->left = NULL;  
    node->right = NULL;  
  
    return(node);  
} 

void inordertree(BST * node, int array[], int *index_ptr)  
{  
    if (node != NULL)  
    {
        inordertree(node->left, array, index_ptr);  
    
        array[*index_ptr] = node->key;  
        (*index_ptr)++; 
    
        inordertree(node->right, array, index_ptr);  
    }    
}  
int* mergeArray(int first[], int second[], int m, int n)
{
    int *merged = new int[m+n];
    int i = 0, j = 0, k = 0; 

    while (i < m && j < n)
    {  
        if (first[i] < second[j])  
        {  
            merged[k] = first[i];  
            i++;  
        }  
        else
        {  
            merged[k] = second[j];  
            j++;  
        }  
        k++;  
    }

    while (i < m)  
    {  
        merged[k] = first[i];  
        i++; k++;  
    }  

    while (j < n)  
    {  
        merged[k] = second[j];  
        j++; k++;  
    }  
  
    return merged;    
}
BST * arrayToBst(int arr[], int start, int end)
{
    if (start > end)  
    return NULL;  
  
    int mid = (start + end)/2;  
    BST *node = newNode(arr[mid]);  
  
    node->left = arrayToBst(arr, start, mid-1);  
  
    node->right = arrayToBst(arr, mid+1, end);  
  
    return node;  
}

BST * merge(BST *root1,BST *root2, int n1, int n2)
{
    int *first = new int [n1];
    int *second = new int [n2];
    int i = 0;
    int j = 0; 
    inordertree(root1, first, &i);
    inordertree(root2, second, &j);

    int *merged = mergeArray(first, second, n1, n2);

    return arrayToBst(merged, 0, n1+n2-1);
}

int main()
{
    BST *root1=NULL,*root2=NULL;
    int n1,n2,key;
    cout<<"ENTER THE NO OF NODES IN 1ST TREE:";
    cin>>n1;
    cout<<"\nENTER THE ELMENTS OF THE TREE: ";
    for(int i=0;i<n1;i++)
    {
        cin>>key;
        root1=insert(root1,key);
    }
    print(root1);
    cout<<"\nENTER THE NUMBER OF NODES IN THE 2ND TREE:";
    cin>>n2;
    cout<<"\nENTER THE ELEMENTS OF THE TREE:";
    for(int i=0;i<n2;i++)
    {
        cin>>key;
        root2=insert(root2,key);
    }
    print(root2);
    BST *node=NULL;
    node=merge(root1,root2,n1,n2);
    cout<<"\nBALANCED TREE:"<<endl;
    print(node);
}