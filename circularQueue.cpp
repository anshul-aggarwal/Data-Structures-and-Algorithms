/*
Circular Queue
*/



#include<iostream>
using namespace std;


void Qdisplay(int q[], int *front, int *rear)
{
	cout << "\nQueue is--\nFront: " << q[*front] << "\nRear: " << q[*rear];
}


void Qinsert(int q[], int *front, int *rear, int size, int element)
{
	if (*front - (*rear + 1) % size == 0)
	{
		cout << "\nError! Queue is full";
	}
	else if (*rear == size - 1)
	{
		*rear = 0;
		q[*rear] = element;
	}
	else
	{
		if (*rear == -1 && *front == -1)
		{
			*rear = 0;
			*front = 0;
		}
		else
		{
			*rear = *rear + 1;
		}
		q[*rear] = element;
	}
	Qdisplay(q, front, rear);
}







int Qdelete(int q[], int *front, int *rear, int size)
{
	int element;
	if (*front == -1 && *rear == -1)
	{
		cout << "\nThe queue is empty!";
		element = 0;
	}
	else if (*front == *rear)
	{
		element = q[*front];
		*front = -1;
		*rear = -1;
	}
	else
	{
		element = q[*front];
		*front = *front + 1;
		if (*front == size) *front = 0;
	}
	return element;
}



int main()
{
	int q[100], n;
	int front = -1, rear = -1;
	int chc;
	int del_ele = 0, ele;
	char opt = 'y';
	cout << "\nEnter the size of queue: ";
	cin >> n;
	while (opt == 'y')
	{
		cout << "\n\nChoose option...\n\n\t1. Insert in queue\t2. Delete from queue\t3. View queue\t4. EXIT :  ";
		cin >> chc;
		switch (chc)
		{
		case 1: cout << "\nEnter the element to be inserted in queue: ";
			cin >> ele;
			Qinsert(q, &front, &rear, n, ele);
			break;
		case 2: del_ele = Qdelete(q, &front, &rear, n);
			cout << "\nThe deleted element is: " << del_ele;
			Qdisplay(q, &front, &rear);
			break;
		case 3: Qdisplay(q, &front, &rear);
			break;
		case 4: opt = 'n';
			break;
		default: cout << "\nInvalid choice...\n";
		}
	}
	return 0;
}