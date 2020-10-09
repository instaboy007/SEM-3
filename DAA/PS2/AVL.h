#include<iostream>
#include<Windows.h>
using namespace std;
#define COUNT 10

class AVL
{
    public:
        int key;
        int balance;
        AVL *left,*right;
};

void display(AVL *root, int space)  
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
    cout<<root->key<<"->"<<root->balance<<"\n";  
  
    // Process left child  
    display(root->left, space);  
}  
  
// Wrapper over print2DUtil()  
void print(AVL *root)  
{  
    // Pass initial space count as 0  
    display(root, 0);  
}

AVL * LL(AVL * root)
{

    AVL* temp = root->left;
    root->left = root->right;
    temp->right = root;
    return temp;
}

AVL * RR(AVL * root)
{
    AVL* temp = root->right;
    root->right = temp->left;
    temp->left = root;
    return temp;
}

int height(AVL * root)
{
    if(root == NULL )
    {
        return 0;
    }
    else
    {
        int lh, rh;
        lh = 1 +height(root->left);
        rh = 1 +height(root->right);
        if(rh > lh)
            return rh;
        else
            return lh;
    }
}

int findbalance(AVL *node)
{
    if(node==NULL)
    {
        return 0;
    }
    else
    {
        int lh, rh;
        lh = height(node->left);
        rh = height(node->right);
        node->balance = lh-rh;
        findbalance(node->right);
        findbalance(node->left);
    }
   // return;
}

AVL * insert(AVL *node,int key)
{
    if(node==NULL)
    {
        node=new AVL;
        node->key=key;
        node->left=NULL;
        node->right=NULL;
        findbalance(node);
        return node;
    }
    else if(key<node->key)
    {
        node->left=insert(node->left,key);
    }
    else if(key>node->key)
    {
        node->right=insert(node->right,key);
    }
    else
        return node;
    
    findbalance(node);
    if(node->balance>1 && key<node->left->key)
    {
        print(node);
        cout<<"PERFORMING RIGHT ROTATION(LL)....."<<endl;
        node=LL(node);
        findbalance(node);
        print(node);
    }
    else if(node->balance<-1 && key>node->right->key)
    {
        print(node);
        cout<<"PERFORMING LEFT ROTATION(RR)....."<<endl;
        node=RR(node);
        findbalance(node);
        print(node);
        cout<<endl;
    }
    else if(node->balance>1 && key > node->left->key)
    {
        print(node);
        cout<<"PERFORMING LEFT ROTATION(RR) ON LEFT SUBTREE....."<<endl;
        node->left=RR(node->left);
        cout<<"PERFORMING RIGHT ROTATION(LL)....."<<endl;
        node=LL(node);
        findbalance(node);
        print(node);
    }
    else if(node->balance < -1 && key < node->right->key)
    {
        print(node);
        cout<<"PERFORMING RIGHT ROTATION(LL) ON RIGHT SUBTREE....."<<endl;
        node->right=LL(node->right);
        cout<<"PERFORMING LEFT ROTATION(RR)....."<<endl;
        node=RR(node);
        findbalance(node);
        print(node);
    }
    return node;
}

AVL * findmin(AVL *Node)
{
    AVL *temp=Node;
    while(temp!=NULL && temp->left!=NULL)
    {
        temp=temp->left;
    }
    return temp;
}

AVL * deletenode(AVL *Node,int key)
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
            AVL *temp=Node->right;
            free(Node);
            return temp;
        }
        else if(Node->right == NULL)
        {
            AVL *temp=Node->left;
            free(Node);
            return temp;
        }
        //NODE HAS TWO CHILD
        else
        {
            //GET THE SMALLEST FROM THE RIGHT SUBTREE AND REPACE THE VALUE & DELETE THE NODE
            AVL *temp = findmin(Node->right);
            Node->key = temp->key;
            Node->right=deletenode(Node->right,temp->key);
        }
    }
    findbalance(Node);
    if(Node->balance >1 && Node->left->balance >=0)
    {
        Node=LL(Node);
    }
    if(Node->balance >1 && Node->left->balance <0)
    {
        Node->left=RR(Node->left);
        Node=LL(Node);
    }
    if(Node->balance <-1 && Node->right->balance<=0)
    {
        Node=RR(Node);
    }
    if(Node->balance <-1 && Node->right->balance >0)
    {
        Node->right=LL(Node->right);
        Node=RR(Node);
    }
    return Node;
}

AVL * nodeleftchild(AVL * root)
{
    AVL* current=root;
    if(current == NULL)
    {
        return NULL;
    }
    if(current->left != NULL && current->right == NULL)
    {
        return current;
    }
    current->left=nodeleftchild(current->left);
    current->right=nodeleftchild(current->right);
    return current;
}

AVL * searchkey(AVL *Node,int key)
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
        return searchkey(Node->right,key);
    }
    else if(key<Node->key)
    {
        return searchkey(Node->left,key);
    }
}

void inorder(AVL *Node)
{
    if(Node!=NULL)
    {
        inorder(Node->left);
        cout<<"  "<<Node->key;
        inorder(Node->right);
    }
}

int findleaf(AVL *Node)
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

void searchbetween(AVL* root,int a,int b)
{
    if(root==NULL)
        return;
    if(a<root->key)
	    searchbetween(root->left,a,b);

	if(a < root->key && b > root->key)
    {
        cout<<root->key<<" ";
    }

    if(b > root->key)
	    searchbetween(root->right,a,b);
}


