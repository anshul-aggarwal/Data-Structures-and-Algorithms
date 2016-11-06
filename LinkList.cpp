/*
Operations on Link List:
a)	Insertion - at the beginning, at the end, at the given location
in the sorted list
b)	Deletion - of first node, of last node, of given item of node, of given item from sorted list
c)	Given a list, split it into two sublists — one for the front half, and one for the back half. If the number of elements is odd, the extra element should go in the front list. So FrontBackSplit() on the list {2, 3, 5, 7, 11} should yield the two lists {2, 3, 5} and {7, 11}.
d)	Given two one-way-link lists A and B. Sort them independently and then Merge as list C.
e)	Two way link list insertion and Deletion
f)	Header link list insertion and deletion
*/



#include<iostream>
using namespace std;

//SINGLY LINKED LIST

struct node {
	int data;
	node *next;
};
node *head = NULL;

void insert_in_beg(int value)
{
	node *newnode;
	newnode = new(node);
	newnode->data = value;
	newnode->next = head;
	head = newnode;
}

void traversal(node *hd)
{
	node *ptr;
	ptr = hd;
	while (ptr != NULL)
	{
		cout << ptr->data << "\n";
		ptr = ptr->next;
	}
}

void insert_at_end(int value)
{
	node *ptr;
	ptr = head;
	while (ptr->next != NULL)
	{
		ptr = ptr->next;
	}
	node *newnode;
	newnode = new(node);
	newnode->data = value;
	newnode->next = NULL;
	ptr->next = newnode;
}

void insert_in_mid(int value, int index)
{
	node *ptr;
	ptr = head;
	for (int i = 0; i < index - 1; i++)
	{
		ptr = ptr->next;
	}
	node *newnode;
	newnode = new(node);
	newnode->data = value;
	newnode->next = ptr->next;
	ptr->next = newnode;
}

void insert_in_sorted_list(int value)
{
	node *ptr;
	ptr = head;
	while(ptr->next->data<=value)
	{
		ptr = ptr->next;
	}
	node *newnode;
	newnode = new(node);
	newnode->data = value;
	newnode->next = ptr->next;
	ptr->next = newnode;
}

void delete_last_node()
{
	node *ptr;
	ptr = head;
	while (ptr->next->next != NULL)
	{
		ptr = ptr->next;
	}
	delete ptr->next;
	ptr->next = NULL;
}

void delete_first_node()
{
	node *ptr;
	ptr = head;
	head = ptr->next;
	delete ptr;
}

void delete_item(int value)
{
	node *ptr;
	ptr = head;
	if (value == ptr->data)
	{
		head = ptr->next;
		delete ptr;
		return;
	}
	while (ptr->next->data != value)
	{
		ptr = ptr->next;
	}
	node *q = ptr->next;
	ptr->next = ptr->next->next;
	delete q;
}

void delete_item_sorted(int value)
{
	node *ptr, *q;
	ptr = head;
	q = head;
	if (value == ptr->data)
	{
		head = ptr->next;
		delete ptr;
		return;
	}
	while (ptr->data < value)
	{
		q = ptr;
		ptr = ptr->next;
	}
	q->next = ptr->next;
	delete ptr;
}

void split_list()
{
	node *headL, *headR;
	node *ptr;
	ptr = head;
	int counter = 0;
	while (ptr != NULL)
	{
		counter++;
		ptr = ptr->next;
	}
	int split = (counter + 1) / 2;
	headL = head;
	ptr = head;
	for (int i = 0;i < split - 1;i++)
	{
		ptr = ptr->next;
	}
	headR = ptr->next;
	ptr->next = NULL;
	cout << "\nLeft List:\n";
	traversal(headL);
	cout << "\nRight List:\n";
	traversal(headR);
}



//DOUBLY LINKED LIST

struct dnode {
	dnode *prev;
	int data;
	dnode *next;
};
dnode *dhead = NULL;

void dinsert_in_beg(int value)
{
	int check = 0;
	dnode *newnode;
	newnode = new(dnode);
	newnode->data = value;
	newnode->next = dhead;
	newnode->prev = NULL;
	if (dhead != NULL) {
		dhead->prev = newnode;check++;
	}
	dhead = newnode;
}

void dtraversal(dnode *dhd)
{
	dnode *ptr;
	ptr = dhd;
	while (ptr != NULL)
	{
		cout << ptr->data << "\n";
		ptr = ptr->next;
	}
}

void dinsert_at_end(int value)
{
	dnode *ptr;
	ptr = dhead;
	while (ptr->next != NULL)
	{
		ptr = ptr->next;
	}
	dnode *newnode;
	newnode = new(dnode);
	newnode->data = value;
	newnode->next = NULL;
	newnode->prev = ptr;
	ptr->next = newnode;
}

void dinsert_in_mid(int value, int index)
{
	dnode *ptr;
	ptr = dhead;
	for (int i = 0; i < index; i++)
	{
		ptr = ptr->next;
	}
	dnode *newnode;
	newnode = new(dnode);
	newnode->data = value;
	newnode->next = ptr;	
	if (ptr->prev != NULL) ptr->prev->next = newnode;
	else dhead = newnode;
	newnode->prev = ptr->prev;
	ptr->prev = newnode;
}

void ddelete_last_node()
{
	dnode *ptr;
	ptr = dhead;
	while (ptr->next->next != NULL)
	{
		ptr = ptr->next;
	}
	delete ptr->next;
	ptr->next = NULL;
}

void ddelete_first_node()
{
	dnode *ptr;
	ptr = dhead;
	dhead = ptr->next;
	delete ptr;
	dhead->prev = NULL;
}

void ddelete_item(int value)
{
	dnode *ptr;
	ptr = dhead;
	while (ptr->data != value)
	{
		ptr = ptr->next;
	}
	if (ptr->prev == NULL) ddelete_first_node();
	else if (ptr->next == NULL)ddelete_last_node();
	else 
	{
		ptr->next->prev = ptr->prev;
		ptr->prev->next = ptr->next;
		delete ptr;
	}	
}


//HEADER LINKED LIST


struct headnode
{
	int size;
	node *first;
};

headnode *head_node;
void inithead()
{
	head_node = new(headnode);
	head_node->size = 0;
	head_node->first = NULL;
}

void hinsert_in_beg(int value)
{
	node *newnode;
	newnode = new(node);
	newnode->data = value;
	newnode->next = head_node->first;
	head_node->first = newnode;
	head_node->size = head_node->size + 1;
}

void htraversal(headnode *hd)
{
	node *ptr;
	ptr = hd->first;
	while (ptr != NULL)
	{
		cout << ptr->data << "\n";
		ptr = ptr->next;
	}
	cout << "\nSizee of the list is: " << head_node->size;
}

void hinsert_at_end(int value)
{
	node *ptr;
	ptr = head_node->first;
	while (ptr->next != NULL)
	{
		ptr = ptr->next;
	}
	node *newnode;
	newnode = new(node);
	newnode->data = value;
	newnode->next = NULL;
	ptr->next = newnode;
	head_node->size = head_node->size + 1;
}

void hinsert_in_mid(int value, int index)
{
	node *ptr;
	ptr = head_node->first;
	for (int i = 0; i < index - 1; i++)
	{
		ptr = ptr->next;
	}
	node *newnode;
	newnode = new(node);
	newnode->data = value;
	newnode->next = ptr->next;
	ptr->next = newnode;
	head_node->size = head_node->size + 1;
}

void hdelete_last_node()
{
	node *ptr;
	ptr = head_node->first;
	while (ptr->next->next != NULL)
	{
		ptr = ptr->next;
	}
	delete ptr->next;
	ptr->next = NULL;
	head_node->size = head_node->size - 1;
}

void hdelete_first_node()
{
	node *ptr;
	ptr = head_node->first;
	head_node->first = ptr->next;
	delete ptr;
	head_node->size = head_node->size - 1;
}

void hdelete_item(int value)
{
	node *ptr;
	ptr = head_node->first;
	if (value == ptr->data)
	{
		head = ptr->next;
		delete ptr;
		return;
	}
	while (ptr->next->data != value)
	{
		ptr = ptr->next;
	}
	node *q = ptr->next;
	ptr->next = ptr->next->next;
	delete q;
	head_node->size = head_node->size - 1;
}


//FUNCTION CALL MENUs

void singlylist(int opt)
{
	int val, ind;
	switch (opt)
	{
	case 1: cout << "\nEnter the value to be inserted: ";
		cin >> val;
		insert_in_beg(val);
		break;
	case 2: cout << "\nEnter the value to be inserted: ";
		cin >> val;
		insert_at_end(val);
		break;
	case 3: cout << "\nEnter the value to be inserted: ";
		cin >> val;
		cout << "\nEnter the index at which the element is to be inserted: ";
		cin >> ind;
		insert_in_mid(val, ind);
		break;
	case 4: cout << "\nEnter the value to be inserted: ";
		cin >> val;
		insert_in_sorted_list(val);
		break;
	case 5: delete_first_node();
		break;
	case 6: delete_last_node();
		break;
	case 7: cout << "\nEnter the value to be deleted: ";
		cin >> val;
		delete_item(val);
		break;
	case 8: cout << "\nEnter the value to be deleted: ";
		cin >> val;
		delete_item_sorted(val);
		break;
	case 9: cout << "\nList is:\n";
		traversal(head);
		break;
	case 10: split_list();
		break;
	}
}

void doublylist(int opt)
{
	int val, ind;
	switch (opt)
	{
	case 1: cout << "\nEnter the value to be inserted: ";
		cin >> val;
		dinsert_in_beg(val);
		break;
	case 2: cout << "\nEnter the value to be inserted: ";
		cin >> val;
		dinsert_at_end(val);
		break;
	case 3: cout << "\nEnter the value to be inserted: ";
		cin >> val;
		cout << "\nEnter the index at which the element is to be inserted: ";
		cin >> ind;
		dinsert_in_mid(val, ind);
		break;
	case 4: ddelete_first_node();
		break;
	case 5: ddelete_last_node();
		break;
	case 6: cout << "\nEnter the value to be deleted: ";
		cin >> val;
		ddelete_item(val);
		break;
	case 7: cout << "\nList is:\n";
		dtraversal(dhead);
		break;
	}
}

void headerlist(int opt)
{
	int val, ind;
	switch (opt)
	{
	case 1: cout << "\nEnter the value to be inserted: ";
		cin >> val;
		hinsert_in_beg(val);
		break;
	case 2: cout << "\nEnter the value to be inserted: ";
		cin >> val;
		hinsert_at_end(val);
		break;
	case 3: cout << "\nEnter the value to be inserted: ";
		cin >> val;
		cout << "\nEnter the index at which the element is to be inserted: ";
		cin >> ind;
		hinsert_in_mid(val, ind);
		break;
	case 4: hdelete_first_node();
		break;
	case 5: hdelete_last_node();
		break;
	case 6: cout << "\nEnter the value to be deleted: ";
		cin >> val;
		hdelete_item(val);
		break;
	case 7: cout << "\nList is:\n";
		htraversal(head_node);
		break;
	}
}

int main()
{
	int mainopt, inneropt, header_initialize = 0;
	char repeat = 'y';
	do
	{
		cout << "\n\n\t\t\t\tM E N U\n\t\t\t       ---------\n\n\t1. Singly Linked List\n\t2. Doubly Linked List\n\t3. Header Linked List\n";
		cin >> mainopt;
		switch (mainopt)
		{
		case 1: cout << "\n\t\t\tSingly Linked List\n\t1. Insert in Beginning\n\t2. Insert at End\n\t3. Insert at specific index\n\t4. Insrt in ordered list\n\t5. Delete from Beginning\n\t6. Delete from End\n\t7. Delete specific item\n\t8. Delete specific item in ordered list\n\t9. Traverse\n\t10. Split List in half\n";
			cin >> inneropt;
			singlylist(inneropt);
			break;
		case 2: cout << "\n\t\t\tDoubly Linked List\n\t1. Insert in Beginning\n\t2. Insert at End\n\t3. Insert at specific index\n\t4. Delete from Beginning\n\t5. Delete from End\n\t6. Delete specific item\n\t7. Traverse\n";
			cin >> inneropt;
			doublylist(inneropt);
			break;
		case 3: cout << "\n\t\t\tHeader Linked List\n\t1. Insert in Beginning\n\t2. Insert at End\n\t3. Insert at specific index\n\t4. Delete from Beginning\n\t5. Delete from End\n\t6. Delete specific item\n\t7. Traverse\n";
			cin >> inneropt;
			if (header_initialize == 0)
			{
				inithead();
				header_initialize = 1;
			}
			headerlist(inneropt);
			break;
		}

		cout << "\nDo you want to perform another operation? (y/n): ";
		cin >> repeat;
	} while (repeat == 'y');
	return 0;
}
