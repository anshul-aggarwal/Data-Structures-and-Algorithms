//Binary Min-heap

#include<iostream>
#define MAXSIZE 127
#define ARRSIZE MAXSIZE+1
using namespace std;

int heap[ARRSIZE];
int size = 0;


void display_array()
{
    cout<<"\n";
    for(int i=1;i<=size;i++)
        cout<<heap[i]<<"\t";
}

int min(int a, int b)
{
    if(heap[a]<=heap[b] || a>=size)
        return a;
    else
        return b;
}
        
void minElement()
{
    if(size>0)
        cout<<"\nSmallest element is: "<<heap[1];
    else
        cout<<"\nHeap Empty!";
}

int parent(int i)
{
    return i/2;
}

int leftC(int i)
{
    return 2*i;
}

int rightC(int i)
{
    return (2*i + 1);
}

void reheapify_insert(int indx)
{
    while(heap[indx]<heap[parent(indx)])
    {
        int tmp = heap[indx];
        heap[indx] = heap[parent(indx)];
        heap[parent(indx)] = tmp;
        indx = parent(indx);
    }
}

void reheapify_delete()
{
    int indx = 1;
    while(heap[indx]>heap[min(leftC(indx), rightC(indx))])
    {
        int repindx = min(leftC(indx), rightC(indx));
        int tmp = heap[indx];
        heap[indx] = heap[repindx];
        heap[repindx] = tmp;
        indx = repindx;
        if (indx>=size) break;
    }
}


void isEmpty()
{
    if(size==0)
        cout<<"\nHeap is empty.";
    else 
        cout<<"\nHeap is not empty.";
}

void insert(int x)
{
    if(size==MAXSIZE)
    {
        cout<<"\nHeap full!";
    }
    else
    {
        heap[++size] = x;
        reheapify_insert(size);
        cout<<"\n"<<x<<" inserted in heap.";
    }
}

void deleteRoot()
{
    if(size == 0) cout<<"Heap empty!";
    else
    {
        int deletedElement = heap[1];
        heap[1] = heap[size--];
        reheapify_delete();
        cout<<"\nDeleted element is: "<<deletedElement;
    }   
}

int main()
{
    heap[0] = -99999999;
    int opt = 0;
    while(opt!=6)
    {
        cout<<"\n\n\t\tMENU\n\t1. Check for empty heap\n\t2. Insert element\n\t3. Find smallest element\n\t4. Delete smallest element\n\t5. Display heap\n\t6. Exit\n\n\tChoose option... ";
        cin>>opt;
        switch(opt)
        {
            case 1: isEmpty();
                    break;
            case 2: int ele;
                    cout<<"\nEnter element to be inserted: ";
                    cin>>ele;
                    insert (ele);
                    break;
            case 3: minElement();
                    break;
            case 4: deleteRoot();
                    break;
            case 5: display_array();
                    break;
        }
    }
    return 0;
}
