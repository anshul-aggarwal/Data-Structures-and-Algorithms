/*
Sort/Search functions application on students database
*/


#include <iostream>
#include<string>
using namespace std;

struct student {
	int rollno;
	string name;
	string branch;
	float cgpa;
	void insert();
	void display();
};

void student::insert()
{
	cout << "\nEnter roll no.: ";
	cin >> rollno;
	cout << "\nEnter name of student: ";
	cin >> name;
	cin.clear();
	cout << "\nEnter branch: ";
	cin >> branch;
	cin.clear();
	cout << "\nEnter CGPA: ";
	cin >> cgpa;
	display();
}

void student::display()
{
	cout << "\n\nROLL NO.: " << rollno << "\nNAME: " << name << "\nBRANCH: " << branch << "\nCGPA: " << cgpa << "\n";
}

//(a)
void linsearch(student arr[], int regno, int db) {
	int flag = -1;
	for (int i = 0;i <db;i++)
	{
		if (arr[i].rollno == regno)
		{
			arr[i].display();
			flag = i;
		}
	}
	if (flag < 0) cout << "\nRecord not found in database!";
}

//(b)
void bubblesort(student a[], int db) {
	for (int i = 0;i < db - 1;i++)
	{
		for (int j = 0;j < db - i - 1; j++)
		{
			if (a[j + 1].rollno < a[j].rollno) {
				student temp = a[j + 1];
				a[j + 1] = a[j];
				a[j] = temp;
			}
		}
	}
}

//(c)
void binsearch(student arr[], int regno, int db)
{
	int flag = -1, mid;
	int upperb = 9, lowerb = 0;
	while (flag < 0 && lowerb <= upperb)
	{
		mid = (upperb + lowerb) / 2;
		if (regno < arr[mid].rollno)upperb = mid - 1;
		else if (regno>arr[mid].rollno)lowerb = mid + 1;
		else if (regno = arr[mid].rollno)
		{
			flag = mid;
			arr[mid].display();
			break;
		}
	}
	if (flag < 0) cout << "\nRecord not found in database";
}


//(d)
void insertionsort(student a[], int db)
{
	for (int i = 0;i < db;i++)
	{
		int j = i;
		while (j >= 0 && a[j - 1].cgpa<a[j].cgpa)
		{
			student temp = a[j - 1];
			a[j - 1] = a[j];
			a[j] = temp;
			j--;
		}
	}
}

int main()
{
	int nos, roll;
	student stdrec[50];
	cout << "Enter the number of students: ";
	cin >> nos;
	for (int i = 0;i < nos;i++) stdrec[i].insert();
	cout << "\n\nEnter a roll no. to be searched using linear search: ";
	cin >> roll;
	linsearch(stdrec, roll, nos);
	cout << "\n\nBubble Sorting the database according to roll no...";
	bubblesort(stdrec, nos);
	cout << "\nThe database after bubble sort is:\n\n\n";
	for (int i = 0;i < nos;i++)
	{
		stdrec[i].display();
	}
	cout << "\n\nEnter a roll no. to be searched using binary search: ";
	cin >> roll;
	binsearch(stdrec, roll, nos);
	cout << "\n\Insertion Sorting the database according to decreasing cgpa...";
	insertionsort(stdrec, nos);
	cout << "\nThe database after insertion sort is:\n\n\n";
	for (int i = 0;i < nos;i++)
	{
		stdrec[i].display();
	}
	cout << "\n";
	return 0;