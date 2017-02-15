//Program to remove duplicate elements from array using BST

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
treenode *nullp = NULL;
int treesize = 0;
int arr[9] = {10,52,14,52,95,10,61,95,26};
int arrsz = 9;

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
{			if (ptr->data > value) ptr = ptr->left;
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

void delete_arr(int indx)
{
  arrsz--;
  for(int i=indx;i<arrsz;i++)
  {
    arr[i] = arr[i+1];
  }
}

void printarr()
{
  for(int i=0;i<arrsz;i++)
  {
    cout<<arr[i]<<" ";
  }
}

int main()
{
	treenode *res;
	cout<<"\nOriginal array of size "<<arrsz<<" : ";
  printarr();
  for(int i=0;i<arrsz;i++)
  {
    res = search(arr[i]);
    if (res !=NULL)
    {
      delete_arr(i);
      i--;
      cout<<"\nDuplicate element "<<arr[i]<<" in array";
    }
    else insert_nr(arr[i]);
  }
  cout<<"\nNew array of size "<<arrsz<<" : ";
  printarr();
	return 0;
}
