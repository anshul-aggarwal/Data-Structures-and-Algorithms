/*
Merge Sort
Quick Sort
Tower of Hanoi
*/


#include<iostream>
#include <limits>
using namespace std;
int a[100];
int maxint = std::numeric_limits<int>::max();
void merge(int, int, int);
void mergesort(int p, int r)
{
	int q;
	if (p < r)
	{
		q = (p + r) / 2;
		mergesort(p, q);
		mergesort(q + 1, r);
		merge(p, q, r);
	}
}

void merge(int p, int q, int r)
{
	const int n1 = q - p + 1;
	const int n2 = r - q;
	int i, j, k;
	int left_a[100], right_a[100];
	for (int m = 0;m < 100;m++)
	{
		left_a[m] = maxint;
		right_a[m] = maxint;
	}
	for (int i = 0;i < n1;i++)
	{
		left_a[i] = a[p + i];
	}
	for (int j = 0;j < n2;j++)
	{
		right_a[j] = a[q + j + 1];
	}

	//left_a[n1] = maxint;
	//right_a[n2] = maxint;
	i = 0;
	j = 0;
	for (k = p; k <= r; k++)
	{
		if (left_a[i] <= right_a[j])
		{
			a[k] = left_a[i];
			i++;
		}
		else
		{
			a[k] = right_a[j];
			j++;
		}
	}
}

int partition(int a[], int indL, int indR)
{
	int x = a[indR];
	int i = indL-1;
	for (int j = indL; j < indR; j++)
	{
		if (a[j] <= x)
		{
			i++;
			int temp = a[i];
			a[i] = a[j];
			a[j] = temp;
			
		}
	}
	int temp2 = a[i+1];
	a[i+1] = a[indR];
	a[indR] = temp2;
	return i+1;
}

void quicksort(int a[], int indL, int indR)
{
	if (indL < indR)
	{
		int indP = partition(a, indL, indR);
		quicksort(a, indL, indP - 1);
		quicksort(a, indP + 1, indR);
	}
}

int pop_stk(int a[], int *top)
{
	//cout << *top<<a[*top];
	//if (*top == -1) {
	//	cout << "\nStack is empty"; return 0;
	//}
	//else {
		int popele = a[*top];
		*top = *top - 1;
		return popele;
	//}
}

void push_stk(int a[], int *top, int element, int size)
{
	//if (*top == size - 1)cout << "\nStack is full";
	//else 
		a[++*top] = element;
}

void tower(int n, int beg[], int aux[], int end[], int *tbeg, int *taux, int *tend)
{
	if (n == 1)
	{
		push_stk(end, tend, pop_stk(beg, tbeg), n + 1);
		return;
	}
	else
	{
		tower(n - 1, beg, end, aux, tbeg, tend, taux);
		//*tend++;
		//end[*tend] = beg[*tbeg];
		//*tbeg--;
		push_stk(end, tend, pop_stk(beg, tbeg), n + 1);
		tower(n - 1, aux, beg, end, taux, tbeg, tend);
	}
}

int main()
{
	int opt;
	cout<<"\nEnter your choice: 1. Merge Sort\t2. Quick Sort\t3. Tower of Hanoi\t";
	cin>>opt;
	switch(opt)
	{
		case 1: int n;
			cout << "\nEnter the number of elements in array: ";
			cin >> n;
			cout << "\nEnter the array:\n";
			for (int i = 0; i < n; i++)
			{
				cin >> a[i];
			}
			mergesort(0, n-1);
			cout << "\nThe array is:\n";
			for (int i = 0;i < n;i++)
			{
				cout << "\t" << a[i];
			}
			break;
		case 2: int n;
			cout << "\nEnter the number of elements in array: ";
			cin >> n;
			cout << "\nEnter the array:\n";
			for (int i = 0; i < n; i++)
			{
				cin >> a[i];
			}
			quicksort(a, 0, n - 1);
			cout << "\nThe array is:\n";
			for (int i = 0;i < n;i++)
			{
				cout << "\t" << a[i];
			}
		case 3: int beg[100], end[100], aux[100], tbeg = 0, tend = 0, taux = 0, n;
			cout << "\nEnter the number of discs: ";
			cin >> n;
			for (int i = n;i >= 1;i--)
			{
				push_stk(beg, &tbeg, i, n + 1);
			}
			tower(n, beg, aux, end, &tbeg, &taux, &tend);
			cout << "\nThe resultant tower is:\n";
			for (int i = 0;i < n;i++)
			{
				cout << "\t" << pop_stk(end, &tend);
			}
	}
	return 0;
}




