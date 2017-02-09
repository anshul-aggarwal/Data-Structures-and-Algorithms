#include<iostream>
using namespace std;

struct node{
    int value;
    struct node* parent;
    struct node* left;
    struct node* right;
}root = NULL;

void preorder(node* rt)
{
    if(rt!=NULL)
        cout<<rt->value;
    if(rt->left!=NULL)
        preorder(rt->left);
    if(rt->right!=NULL)
        preorder(rt->right);
}

void inorder(node* rt)
{
    if(rt->left!=NULL)
        inorder(rt->left);
    if(rt!=NULL)
        cout<<rt->value;
    if(rt->right!=NULL)
        inorder(rt->right);
}

void postorder(node* rt)
{
    if(rt->left!=NULL)
        postorder(rt->left);
    if(rt->right!=NULL)
        postorder(rt->right);
    if(rt!=NULL)
        cout<<rt->value;
}

void insert(int val)
{
    node* newnode;
    newnode = new(node);
    newnode->value = val;
    newnode->parent = NULL;
    newnode->left = NULL;
    newnode->right = NULL;
    
    if(root == NULL)
    {
        root = newnode;
    }
    else
    {
        node* ptr;
        ptr = root;
        while((ptr->left!=NULL && val < ptr->value)||(ptr->right!=NULL && val > ptr->value))
        {
            if(val < ptr->value) ptr = ptr->left;
            else if(val > ptr->value) ptr = ptr->right;
        }
        if(val < ptr->value)
        {
            ptr->left = newnode;
            newnode->parent = ptr;
        }
        else if (val > ptr->value)
        {
            ptr->right = newnode;
            newnode->parent = ptr;
        }
    }
}
            
    
}
