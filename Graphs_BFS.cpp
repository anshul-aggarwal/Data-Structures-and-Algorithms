/*
Program to find approachable nodes from a given source of a given
graph using queue as an intermediate data structure (BFS).
*/

#include<iostream>
#include<queue>
#define INF 10000
using namespace std;

struct node {
	int id;
	int dist;	//Distance from source
	char color;
	node *parent;
};
node *source = NULL;
node *addr[10];

bool edge[10][10];
int cur_id = 0;

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
		newnode->dist = 0;
	}
	else
	{
		char opt = 'y';
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
		newnode->dist = newnode->parent->dist + 1;
	}
	cur_id++;
}

void approachale_nodes(int nodeid, int lvl)
{
	addr[nodeid]->color = 'b';
	for (int i = 0;i < n;i++)
	{
		if (edge[nodeid][i] == true)
		{
			if (addr[i]->color != 'b')cout << "\nNode is approachable to node " << i << " in " << lvl << " steps.";
			approachale_nodes(i, lvl + 1);
		}
	}
}

void BFS()
{
	for (int i = 1; i < n; i++)
	{
		addr[i]->color = 'w';
		addr[i]->dist = INF;
		addr[i]->parent = NULL;
	}
	source->color = 'g';
	source->dist = 0;
	source->parent = NULL;
}



int main()
{
	cout << "Enter the no. of nodes: ";
	cin >> n;
	for (int i = 0;i < n;i++)
	{
		create();
	}
	int nd;
	cout << "\nEnter the source node for starting paths: ";
	cin >> nd;
	approachale_nodes(nd, 1);
	return 0;
}