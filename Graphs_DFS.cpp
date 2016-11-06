/*
Program to traverse various nodes of a given graph using stack as an
intermediate data structure (DFS).
*/

#include<iostream>
using namespace std;

struct node {
	int id;
	int d;
	int f;
	char color;
	node *parent;
};
node *source = NULL;
node *addr[10];

bool edge[10][10];
int cur_id = 0;
int time = 0;

int n;	//No. of nodes

void create()
{
	node *newnode;
	newnode = new(node);
	addr[cur_id] = newnode;
	newnode->color = 'w';
	newnode->id = cur_id;
	edge[cur_id][cur_id] = true;
	if (source == NULL)
	{
		source = newnode;
		newnode->parent = NULL;
	}
	else
	{
		char opt;
		cout << "Do you want to create a link to node " << cur_id << "? (y/n): ";
		cin >> opt;
		int p = cur_id;
		while (opt == 'y')
		{
			int link;
			cout << "\nEnter the node to be linked with node " << cur_id << ": ";
			cin >> link;
			edge[link][cur_id] = true;
			edge[cur_id][link] = true;
			if (link < p) p = link;
			cout << "Do you want to create another link for this node? (y/n): ";
			cin >> opt;
		}
		newnode->parent = addr[p];
	}
	cur_id++;
}


void DFS_Visit(node *u)
{
	u->color = 'g';
	time = time + 1;
	u->d = time;
	for (int j = 0;j < n;j++)
	{
		if (edge[u->id][j])
		{
			node *ptr = addr[j];
			if (ptr->color == 'w')
			{
				ptr->parent = u;
				DFS_Visit(ptr);
			}
		}
	}
	u->color = 'b';
	u->f = ++time;
	cout << "\n" << u->id << "\t" << u->d << "\t" << u->f;
}

void DFS()
{
	for (int i = 0;i < n;i++)
	{
		addr[i]->color = 'w';
		addr[i]->parent = NULL;
	}

	for (int i = 0;i < n;i++)
	{
		if (addr[i]->color == 'w')
			DFS_Visit(addr[i]);
	}
}


int main()
{
	cout << "Enter the no. of nodes: ";
	cin >> n;
	for (int i = 0;i < n;i++)
	{
		create();
	}
	cout << "\nNode\td\tf";
	cout << "\n-----------------------------------------------------";
	DFS();
	return 0;
}