/*
Binary Search Trees:

a)	Search a given item (Recursive & Non-Recursive) 
b)	Insertion of a new node
c)	Maximum element of the BST
d)	Minimum element of the BST
e)	Successor  of the BST
f)	Delete a given node from the BST
*/

#include<iostream>
using namespace std;

struct treenode
{
	int data;
	treenode *parent;
	treenode *left;
	treenode *right;
}*treeroot = NULL;

treenode *a[100];
int top = -1;
treenode *nullp = NULL;
int treesize = 0;

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

void insert_nr(int value)
{
	treesize++;
	treenode *newnode;
	newnode = new(treenode);
	newnode->data = value;
	newnode->left = NULL;
	newnode->parent = NULL;
	newnode->right = NULL;
	if (treeroot == NULL)
	{
		treeroot = newnode;
	}
	else
	{
		treenode *ptr;
		ptr = treeroot;
		while ((!(ptr->left == NULL && value<ptr->data)) && (!(ptr->right == NULL && value>ptr->data)))
		{
			if (ptr->data > value) ptr = ptr->left;
			else if (ptr->data < value) ptr = ptr->right;
		}
		if (ptr->data > value)
		{
			ptr->left = newnode;
			newnode->parent = ptr;
		}
		else if (ptr->data < value) 
		{
			ptr->right = newnode;
			newnode->parent = ptr;
		}
	}
}

void insert_rec(treenode *node, treenode *root)
{
	char side = 'N';
	if (root == NULL)
	{
		if (side == 'N') root = node;
		else
		{
			root = node->parent;
			if (side == 'L') root->left = node;
			else if (side == 'R') root->right = node;
		}
	}
	else if (node->data < root->data)
	{
		node->parent = root;
		side = 'L';
		insert_rec(node, root->left);
	}
	else if (node->data > root->data)
	{
		node->parent = root;
		side = 'R';
		insert_rec(node, root->right);
	}
}

void insert_r(int value)
{
	treesize++;
	treenode *newnode;
	newnode = new(treenode);
	newnode->data = value;
	newnode->left = NULL;
	newnode->parent = NULL;
	newnode->right = NULL;
	insert_rec(newnode, treeroot);
}

void inorder_nr()
{
	int size = treesize;
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
		while (size != 0)
		{
			if (a[top] != NULL)
			{
				ptr = pop_stk();
				cout << ptr->data<<" ";
				size--;
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

treenode* search(int value)
{
	treenode *ptr;
	ptr = treeroot;
	while (ptr != NULL)
	{
		if (ptr->data > value) ptr = ptr->left;
		else if (ptr->data < value) ptr = ptr->right;
		else if (ptr->data == value) break;
	}
	return ptr;
}

treenode* maximum_ele(treenode *root)
{
	treenode *ptr;
	ptr = root;
	while (ptr->right != NULL)
	{
		ptr = ptr->right;
	}
	return ptr;
}

treenode* minimum_ele(treenode *root)
{
	treenode *ptr;
	ptr = root;
	while (ptr->left != NULL)
	{
		ptr = ptr->left;
	}
	return ptr;
}

treenode* successor(treenode *element)
{
	if (element->right != NULL) return minimum_ele(element->right);
	treenode *ptr = element->parent;
	while (ptr != NULL && element == ptr->right)
	{
		element = ptr;
		ptr = ptr->parent;
	}
	return ptr;
}

void transplant(treenode *u, treenode *v)
{
	if (u->parent == NULL) treeroot = v;
	else if (u == u->parent->left)u->parent->left = v;
	else u->parent->right = v;
	if (v != NULL) v->parent = u->parent;
}

void treedelete(treenode *ele)
{
	if (ele->left == NULL) transplant(ele, ele->right);
	else if (ele->right == NULL) transplant(ele, ele->left);
	else
	{
		treenode *ptr;
		ptr = minimum_ele(ele->right);
		if (ptr->parent != ele)
		{
			transplant(ptr, ptr->right);
			ptr->right = ele->right;
			ptr->right->parent = ptr;
		}
		transplant(ele, ptr);
		ptr->left = ele->left;
		ptr->left->parent = ptr;
	}
}

int main()
{
	int val;
	int choice; 
	char opt = 'y';
	int exit = 0;
	treenode *res;
	while (exit == 0)
	{
		cout << "\n\t\t\t\t.M.E.N.U.\n\t1. Insert in tree\n\t2. Search\n\t3. Maximum element\n\t4. Minimum element\n\t5. Successor\n\t6. Delete element\n\t7. EXIT";
		cout << "... ";
		cin >> choice;
		switch (choice)
		{
		case 1: opt = 'y';
			while (opt == 'y')
			{
				cout << "\nEnter the value to be inserted: ";
				cin >> val;
				insert_nr(val);
				cout << "\nDo you want to insert another value (y/n): ";
				cin >> opt;
			}
			inorder_nr();
			break;
		case 2: cout << "\nEnter the value to be searched: ";
			cin >> val;
			res = search(val);
			if (res !=NULL)	cout << "\nElement found!\n\tParent: " << res->parent->data;
			else cout << "\nElement not found!";
			break;
		case 3:res = maximum_ele(treeroot);
			cout << "\nThe Maximum element in tree is: " << res->data;
			break;
		case 4: res = minimum_ele(treeroot);
			cout << "\nThe Minimum element in tree is: " << res->data;
			break;
		case 5: cout << "\nEnter the value whose successor is to be found: ";
			cin >> val;
			treenode *pred;
			pred = search(val);
			res = successor(pred);
			cout << "\nThe successor is: " << res->data;
			break;
		case 6: cout << "\nEnter the value to be deleted: ";
			cin >> val;
			res = search(val);
			treedelete(res);
			cout << "\nThe remaining tree is:\n";
			inorder_nr();
			break;
		case 7: exit = 1;
			break;
		}
	}
	cout << "\n";
	return 0;
}