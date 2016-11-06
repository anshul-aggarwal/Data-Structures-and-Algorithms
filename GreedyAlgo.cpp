/*
0/1 and partial knapsack
*/

#include<iostream>
using namespace std;

struct ressol {
	float val;
	float ben;
	float unitben;
	int ord;
}res[10];

void insertionsort(ressol a[], int n)
{
	for (int i = 0;i < n;i++)
	{
		int j = i;
		while (j >= 0 && a[j - 1].unitben>a[j].unitben)
		{
			ressol temp = a[j - 1];
			a[j - 1] = a[j];
			a[j] = temp;
			j--;
		}
	}
}

void partial_knapsack()
{
	float knapsack = 0, max_knapsack = 50, net_benefit = 0;
	int n, k;
	cout << "Enter the no. of values: ";
	cin >> n;
	cout << "\nEnter the value set:\n";
	for (int i = 0;i < n;i++)
	{
		cout << "Value " << i + 1 << ": ";
		cin >> res[i].val;
	}
	cout << "\nEnter the net benefits corresponding to each value in the set:\n";
	for (int i = 0;i < n;i++)
	{
		cout << "Benefit for Value " << i + 1 << ": ";
		cin >> res[i].ben;
		res[i].unitben = res[i].ben / res[i].val;
		res[i].ord = i;
	}
	insertionsort(res, n);
	k = n-1;
	while (knapsack < max_knapsack && k>=0)
	{
		if (max_knapsack - knapsack >= res[k].val)
		{
			knapsack += res[k].val;
			net_benefit += res[k].ben;
			cout << "\n\nAdded in full value " << res[k].ord << " (" << res[k].val << ") to knapsack.";
			cout << "\nKnapsack contents: " << knapsack;
			cout << "\nNet Benefit: " << net_benefit;
			k--;
		}
		else
		{
			net_benefit += res[k].unitben * (max_knapsack - knapsack);
			knapsack += max_knapsack - knapsack;
			cout << "\n\nAdded partially value " << res[k].ord << " (" << res[k].val << ") to knapsack.";
			cout << "\nKnapsack contents: " << knapsack;
			cout << "\nNet Benefit: " << net_benefit;
			break;
		}
	}
}

void zeroone_knapsack()
{
	float knapsack = 0, max_knapsack = 50, net_benefit = 0;
	int n, k;
	cout << "Enter the no. of values: ";
	cin >> n;
	cout << "\nEnter the value set:\n";
	for (int i = 0;i < n;i++)
	{
		cout << "Value " << i + 1 << ": ";
		cin >> res[i].val;
	}
	cout << "\nEnter the net benefits corresponding to each value in the set:\n";
	for (int i = 0;i < n;i++)
	{
		cout << "Benefit for Value " << i + 1 << ": ";
		cin >> res[i].ben;
		res[i].unitben = res[i].ben / res[i].val;
		res[i].ord = i;
	}
	insertionsort(res, n);
	k = n - 1;
	while (knapsack < max_knapsack && k >= 0)
	{
		if (max_knapsack - knapsack >= res[k].val)
		{
			knapsack += res[k].val;
			net_benefit += res[k].ben;
			cout << "\n\nAdded in full value " << res[k].ord << " (" << res[k].val << ") to knapsack.";
			cout << "\nKnapsack contents: " << knapsack;
			cout << "\nNet Benefit: " << net_benefit;
			k--;
		}
		else
		{
			k--;
		}
	}
}


int main()
{
	partial_knapsack();
	zeroone_knapsack();
	return 0;
}