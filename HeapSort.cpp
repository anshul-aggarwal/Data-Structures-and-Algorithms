/*
Heap Sort
*/

#include<iostream>
using namespace std;

int heap[100];
int hsize, length;

int parent(int i)
{
	return i / 2;
}

int left(int i)
{
	return 2 * i;
}

int right(int i)
{
	return (2 * i + 1);
}

void max_heapify(int i)
{
	int l = left(i);
	int r = right(i);
	int largest;
	if (l <= length && heap[l] > heap[i])
	{
		largest = l;
	}
	else largest = i;
	if (r <= length && heap[r] > heap[largest])
	{
		largest = r;
	}
	if (largest != r)
	{
		int temp;
		temp = heap[largest];
		heap[largest] = heap[i];
		heap[i] = temp;
		max_heapify(largest);
	}
}

void build_max_heap()
{
	for (int i = hsize/2;i >= 1;i--)
	{
		max_heapify(i);
	}
}

void heapsort()
{
	build_max_heap();
	for (int i = hsize; i >= 2;i--)
	{
		int temp = heap[1];
		heap[1] = heap[i];
		length--;
		max_heapify(1);
	}
}

int main()
{
	cout << "\nEnter heap size: ";
	cin >> hsize;
	length = hsize;
	cout << "Enter the heap:\n";
	for (int i = 1;i <= hsize;i++)
	{
		cin >> heap[i];
	}
	heapsort();
	cout << "Sorted array is:\n";
	for (int i = 1;i <= hsize;i++)
	{
		cout << heap[i];
	}
	return 0;
}