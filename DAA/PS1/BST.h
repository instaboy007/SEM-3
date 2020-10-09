#include<iostream>
#include<bits/stdc++.h> 
using namespace std;
#define COUNT 10  

class BST
{
    public:
        int key;
        BST *left,*right;
};

BST * insert(BST *Node,int key)
{
    if(Node==NULL)
    {
        BST *temp=new BST;
        temp->key=key;
        temp->left=NULL;
        temp->right=NULL;
        return temp;
    }
    else if(Node->key>key && key!=Node->key)
    {
        Node->left=insert(Node->left,key);
    }
    else if(Node->key<key && key!=Node->key)
    {
        Node->right=insert(Node->right,key);
    }
    else
    {
        cout<<"\nELEMENT ALREADY PRESENT";
    }
    
    return Node;    
}

BST * search(BST *Node,int key)
{
    if(Node==NULL)
    {
        cout<<"\nKEY NOT PRESENT\n";
    }
    else if(Node->key == key )
    {
        return Node;
    }
    else if(key>Node->key)
    {
        return search(Node->right,key);
    }
    else if(key<Node->key)
    {
        return search(Node->left,key);
    }
}

BST * searchval(BST *Node,int key,int *count)
{
    if(count!=NULL)
    {
        *count+=1;
    }
    if(Node==NULL ||key==Node->key)
        return Node;
    if(key>Node->key)
        return searchval(Node->right,key,count);
    return searchval(Node->left,key,count);
}

int findleaf(BST *Node)
{
    if(Node==NULL)
    {
        return 0;
    }
    if(Node->left==NULL && Node->right==NULL)
    {
        return 1;
    }
    else
    {
        return findleaf(Node->left) + findleaf(Node->right);
    }   
}
BST * findmin(BST *Node)
{
    BST *temp=Node;
    while(temp!=NULL && temp->left!=NULL)
    {
        temp=temp->left;
    }
    return temp;
}

BST * findmax(BST *Node)
{
    BST *temp=Node;
    while(temp!=NULL && temp->right!=NULL)
    {
        temp=temp->right;
    }
    return temp;
}

BST * deletenode(BST *Node,int key)
{
    if(Node==NULL)
    {
        return Node;
    }
    if(key<Node->key)
    {
        Node->left=deletenode(Node->left,key);
    }
    else if(key>Node->key)
    {
        Node->right=deletenode(Node->right,key);
    }
    else if(Node->key==key)
    {
        //NODE HAS ONE OR NO CHILD
        if(Node->left== NULL)
        {
            BST *temp=Node->right;
            free(Node);
            return temp;
        }
        else if(Node->right == NULL)
        {
            BST *temp=Node->left;
            free(Node);
            return temp;
        }
        //NODE HAS TWO CHILD
        else
        {
            //GET THE SMALLEST FROM THE RIGHT SUBTREE AND REPACE THE VALUE & DELETE THE NODE
            BST * small=NULL;
            small= findmin(Node->right);
            Node->key = small->key;
            Node->right=deletenode(Node->right,small->key);
        }
    }
    return Node;
}

void inorder(BST *Node)
{
    if(Node!=NULL)
    {
        inorder(Node->left);
        cout<<"  "<<Node->key;
        inorder(Node->right);
    }
}

void preorder(BST *Node)
{
    if(Node!=NULL)
    {
        cout<<" "<<Node->key;
        preorder(Node->left);
        preorder(Node->right);
    }

}
void postorder(BST *Node)
{
    if(Node!=NULL)
    {
        preorder(Node->left);
        preorder(Node->right);
        cout<<" "<<Node->key;
    }

}

int height(BST *Node)
{
    if(Node==NULL)
    {
        return 0;
    }
    int left=height(Node->left);
    int right=height(Node->right);
    return (left>right)? left+1 : right+1 ;
}

int printlevel(BST *Node,int level)
{
    if(Node==NULL)
    {
        return 0;
    }
    if(level==1)
    {
        cout<<Node->key<<" ";
    }
    else if(level>1)
    {
        printlevel(Node->left,level-1);
        printlevel(Node->right,level-1);
    }
}

int printalllevels(BST *Node)
{
    int h = height(Node);
    for(int i=1;i<=h;i++)
    {
        cout<<"\nLEVEL "<<i<<":  ";
        printlevel(Node,i);
        cout<<"\n";
    }
}

int numberofnodes(BST *Node)
{
    if(Node==NULL)
    {
        return 0;
    }
    else
    {
        return numberofnodes(Node->left) + numberofnodes(Node->right) +1;
    } 
}

void display(BST *root, int space)  
{  
    // Base case  
    if (root == NULL) 
        return;  
    // Increase distance between levels  
    space += COUNT;  
  
    // Process right child first  
    display(root->right, space);  
  
    // Print current node after space  
    // count  
    cout<<endl;  
    for (int i = COUNT; i < space; i++)  
        cout<<" ";  
    cout<<root->key<<"\n";  
  
    // Process left child  
    display(root->left, space);  
}  
  
// Wrapper over print2DUtil()  
void print(BST *root)  
{  
    // Pass initial space count as 0  
    display(root, 0);  
}  
