/*
Pre-order
In-order
Post-order
*/

#include<iostream>
using namespace std;

struct treenode
{
	treenode *parent;
	int data;
	treenode *left;
	treenode *right;
};
treenode *treeroot = NULL;
treenode *nullp = NULL;
int treesize = 0;

//TEST NODES

treenode *tr1, *tr2, *tr3;
void valassign()
{
	treenode *tr1, *tr2, *tr3;
	tr1 = new(treenode);
	tr2 = new(treenode);
	tr3 = new(treenode);


	tr1->parent = NULL;
	tr1->data = 5;
	tr1->left = tr2;
	tr1->right = tr3;

	tr2->parent = tr1;
	tr2->data = 3;
	tr2->left = NULL;
	tr2->right = NULL;

	tr3->parent = tr1;
	tr3->data = 7;
	tr3->left = NULL;
	tr3->right = NULL;

	treesize = 3;

	treeroot = tr1;
}



treenode *a[100];
int top = -1;

treenode* pop_stk()
{
	treenode *popele = a[top];
	top = top - 1;
	return popele;
}


void push_stk(treenode *element)
{
	a[++top] = element;
}

void preorder_rec(treenode *root)
{
	cout << root->data;
	if (root->left != NULL)preorder_rec(root->left);
	if (root->right != NULL)preorder_rec(root->right);
}

void inorder_rec(treenode *root)
{
	if (root->left != NULL)inorder_rec(root->left);
	cout << root->data;
	if (root->right != NULL)inorder_rec(root->right);
}

void postorder_rec(treenode *root)
{
	if (root->left != NULL)postorder_rec(root->left);
	if (root->right != NULL)postorder_rec(root->right);
	cout << root->data;
}

void preorder_nr()
{
	push_stk(nullp);
	treenode *ptr;
	ptr = treeroot;
	while (ptr != NULL)
	{
		while (ptr != NULL)
		{
			cout << ptr->data;
			if (ptr->right != NULL)
			{
				push_stk(ptr->right);
			}
			ptr = ptr->left;
		}
		ptr = pop_stk();
	}
}

void inorder_nr()
{
	push_stk(nullp);
	treenode *ptr;
	ptr = treeroot;
	while (ptr != NULL)
	{
		while (ptr != NULL)
		{
			push_stk(ptr);
			ptr = ptr->left;
		}
		while (treesize != 0)
		{
			if (a[top] != NULL)
			{
				ptr = pop_stk();
				cout << ptr->data;
				treesize--;
			}
			if (ptr->right != NULL)
			{
				ptr = ptr->right;
				break;
			}
			//else break;
		}
	}
}

void postorder_nr()  //not done correctly, do it
{
	push_stk(nullp);
	treenode *ptr;
	ptr = treeroot;
	while (ptr != NULL)
	{
		while (ptr != NULL)
		{
			push_stk(ptr);
			ptr = ptr->left;
		}
		while (treesize != 0)
		{
			if (a[top] != NULL)
			{
				ptr = pop_stk();
				cout << ptr->data;
				treesize--;
			}
			
			if (ptr->right != NULL)
			{
				ptr = ptr->right;
				break;
			}
			//else break;
		}
	}
}

int main()
{
	valassign();
	inorder_nr();
	return 0;
}