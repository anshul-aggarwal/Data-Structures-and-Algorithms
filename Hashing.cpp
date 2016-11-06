/*
Hashing
*/

#include<iostream>
using namespace std;

int dataarr[100];
int opt, sz, modval;

void collision_handle(int, int);

void hashing()
{
	int data = -1;
	cout << "\nEnter the keys (-1 to stop):\n";
	cin >> data;
	while (data >= 0)
	{
		int hashval = data % modval;
		if (dataarr[hashval] != -1)
		{
			collision_handle(hashval, data);
		}
		else dataarr[hashval] = data;
		cin >> data;
	}
}

void collision_handle(int hashval, int data)
{
	int i;
	switch (opt)
	{
	case 1: 
		for (i = 1;i < sz;i++) {
			if (dataarr[(hashval + i) % sz] == -1) {
				dataarr[(hashval + i) % sz] = data;
				break;
			}
		}
		if (i == sz) cout << "\nFULL!";
		break;
	case 2: 
		int comp = 0;
		for (i = 1;(hashval + i*i) % sz != hashval;i++) {
			if (dataarr[(hashval + i*i) % sz] == -1) {
				dataarr[(hashval + i*i) % sz] = data;
				comp = 1;
				break;
			}
		}
		if (comp == 0) cout << "\nUNSUCCESSFUL!";
		break;
	}
}

void retrieve(int key)
{
	int hashval = key%modval;
	int index = -1, i;
	switch (opt)
	{
	case 1:
		for (i = 0;i < sz;i++) {
			if (dataarr[(hashval + i) % sz] == key) {
				index = (hashval + i) % sz;
				dataarr[index] = -1;
				break;
			}
		}
		break;
	case 2:
		for (i = 1;(hashval + i*i) % sz != hashval;i++) {
			if (dataarr[(hashval + i*i) % sz] == key) {
				index = (hashval + i*i) % sz;
				dataarr[index] = -1;
				break;
			}
		}
		break;
	}
	if (index != -1) cout << "\nThe key was retrieved from index " << index;
	else cout << "\nKey not found!";
}

int main()
{
	cout << "\n\tMENU\n\t1. Linear probing\n\t2. Quadratic probing\nSelect mode: ";
	cin >> opt;
	cout << "Enter the maximum storage space: ";
	cin >> sz;
	cout << "\nEnter the mod value for hashing function: ";
	cin >> modval;
	for (int i = 0;i < 100;i++) dataarr[i] = -1;
	hashing();
	char choice = 'y';
	while (choice == 'y')
	{
		int key;
		cout << "\nEnter key to be retrieved: ";
		cin >> key;
		retrieve(key);
		cout << "\nDo you want to retrieve another key? (y/n): ";
		cin >> choice;
	}
	return 0;
}
