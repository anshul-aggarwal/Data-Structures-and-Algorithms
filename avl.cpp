#include<iostream>
#include<algorithm>
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

int height(node* ptr)
{
    int ht=0;
    if(ptr!=NULL)
    {
        int l_ht = height(ptr->left);
        int r_ht = height(ptr->right);
        int max_ht = max(l_ht, r_ht);
        h = max_ht + 1;
    }
    return h;
}

int h_diff(node* ptr)
{
    int lh = height(ptr->left);
    int rh = height(ptr->right);
    bal_number = lh - rh;
    return bal_number;
}

void balance()
{

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
    balance_avl();
}


int main()
{
    int opt = 1;
    while(opt!=6)
    {
        cout<<"\n\tAVL TREE\n1. Insert values\n2. Preorder Traversal\n3. Inorder Traversal\n4. Postorder Traversal\n5. Delete value\n6. Exit\nChoose option... ";
        cin>>opt;
        switch(opt)
        {
            case 1: int n;
                    cout<<"\nEnter the number of values to be inserted: ";
                    cin>>n;
                    for(int i=0;i<n;i++)
                    {
                        int v;
                        cout<<"\nEnter value to be inserted: ";
                        cin>>v;
                        insert(v);
                    }
                    break;
            case 2: preorder(root);
                    break;
            case 3: inorder(root);
                    break;
            case 4: postorder(root);
                    break;
            case 5: int v;
                    cout<<"\nEnter value to be deleted: ";
                    cin>>v;
                    deleteval(v);
                    break;
            case 6: break;
            default: cout<<"\nInvalid choice!";
                     break;
        }
    }
    return 0;
}
