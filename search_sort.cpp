/*
a)	Insertion Sort
b)	Bubble Sort
c)	Selection Sort
d)	Linear Search
e)	Binary Search
f)	Shell sort
*/


#include<iostream>
#include<math.h>
using namespace std;


int counter = 0;
void linsearch(int arr[], int size)
{
	int element;
	cout << "\nEnter the element to be searched";
	cin >> element;
	int flag = -1;
	for (int i = 0;i <size;i++)
	{
		counter++;
		if (arr[i] == element)
		{
			cout << "\nElement found at index " << i;
			flag = i;
			break;
		}
	}
	cout << counter;
	if (flag < 0) cout << "\nElement not found in array";
}

void binsearch(int arr[], int size)
{
	int element;
	cout << "\nEnter the element to be searched";
	cin >> element;
	int flag = -1, mid;
	int upperb = size - 1, lowerb = 0;
	while (flag < 0 && lowerb <= upperb)
	{
		counter++;
		mid = (upperb + lowerb) / 2;
		if (element < arr[mid])upperb = mid - 1;
		else if (element>arr[mid])lowerb = mid + 1;
		else if (element = arr[mid])
		{
			flag = mid;
			cout << "\nElement found at index " << flag;
			break;
		}
	}
	cout << counter;
	if (flag < 0) cout << "\nElement not found in array";
}


void bubblesort(int a[], int n) {
	for (int i = 0;i < n-1;i++)
	{
		for (int j = 0;j < n - i - 1; j++)
		{
			counter++;
			if (a[j + 1] < a[j]) {
				int temp = a[j + 1];
				a[j + 1] = a[j];
				a[j] = temp;
			}
		}
	}
	cout << counter;
}

void selectionsort(int a[], int n)
{
	int small, flag;
	for (int i = 0;i < n;i++)
	{
		small = a[i]; 
		flag = i;
		for (int j = i + 1;j < n;j++)
		{
			counter++;
			if (a[j] < small) {
				small = a[j];
				flag = j;
			}
		}
			a[flag] = a[i];
			a[i] = small;
	}
	cout << counter;
}


void insertionsort(int a[], int n)
{
	for (int i = 0;i < n;i++)
	{
		int j = i;
		while (j >= 0 && a[j - 1]>a[j])
		{
			counter++;
			int temp = a[j - 1];
			a[j - 1] = a[j];
			a[j] = temp;
			j--;
		}
	}
	cout << counter;
}


void shellsort(int a[], int n)
{
	int gap, temp, i, j;
	for (int k = log(n) / 0.3010; k >= 1; k--)
	{
		gap = n / (2 ^ k);
		for (i = gap;i < n;i++)
		{
			temp = a[i];
			for (j = i;j >= gap && a[j - gap] > temp;j = j - gap)
			{
				counter++;
				a[j] = a[j - gap];
			}
			a[j] = temp;
		}
	}
	cout << counter;
}

int main()
{
	int arr[100];
	int n, i, opt;
	cout << "Enter the number of elements in array: ";
	cin >> n;
	cout << "\nEnter the array:\n";
	for (i = 0;i < n;i++)
	{
		cin >> arr[i];
	}

	cout << "\n\n\t\t\t.M.E.N.U.";
	cout << "\n\t1. Bubble Sort\n\t2. selectionsort Sort\n\t3. Insertion Sort\n\t4. Shell Sort\n\t5. Linear Search\n\t6. Binary Search\nChoose option...";
	cin >> opt;
	switch (opt) {
	case 1: bubblesort(arr, n);
		break;
	case 2: selectionsort(arr, n);
		break;
	case 3: insertionsort(arr, n);
		break;
	case 4: shellsort(arr, n);
		break;
	case 5: linsearch(arr, n);goto SKIPDSP;
		break;
	case 6: binsearch(arr, n);goto SKIPDSP;
		break;
	default: cout << "\nInvalid choice..."; goto SKIPDSP;
	}
	cout << "\n\nThe sorted array is:\n";
	for (i = 0;i < n;i++)
	{
		cout << arr[i] << "\t";
	}
	SKIPDSP:
	return 0;
}

