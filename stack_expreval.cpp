/*
a) Create functions for push and pop operations of stack. 
b) Write a function to convert an infix expression to postfix expression. Pass a one dimensional character array P to the function as input (infix exp) and return character array Q (postfix exp). Test your program for following input 
P : ( A – (B / C ) * D + E ) * F % G 

c) Write a function for the evaluation of a given postfix expression. For testing pass the postfix expression Q of part b and supply following set of values. 
A = 90, B = 50, C = 2, D = 3, E = 1, F = 2, G = 5
*/

#include<iostream>
using namespace std;

char pop_stk(char a[], int *top)
{
	//cout << *top<<a[*top];
	if (*top == -1) {
		cout << "\nStack is empty"; return 0;
	}
	else {
		char popele = a[*top];
		*top = *top - 1;
		return popele;
	}
}

void push_stk(char a[], int *top, char element, int size)
{
	if (*top == size - 1)cout << "\nStack is full";
	else a[++*top] = element;
}


int pop_stk_i(int a[], int *top)
{
	//cout << *top<<a[*top];
	if (*top == -1) {
		cout << "\nStack is empty"; return 0;
	}
	else {
		int popele = a[*top];
		*top = *top - 1;
		return popele;
	}
}

void push_stk_i(int a[], int *top, int element, int size)
{
	if (*top == size - 1)cout << "\nStack is full";
	else a[++*top] = element;
}

int main()
{
	char p[100], stk[100], q[100];
	int n, top = 0, k = 0;
	cout << "Enter the length of string: ";
	cin >> n;
	cout << "Enter expression: ";
	for (int i = 0;i < n;i++)
	{
		cin >> q[i];
	}
	q[n] = ')';
	stk[0] = '(';
	for (int i = 0; i <= n;i++)
	{
		//if (q[i] == '1' || q[i] == '2' || q[i] == '3' || q[i] == '4' || q[i] == '5' || q[i] == '6' || q[i] == '7' || q[i] == '8' || q[i] == '9' || q[i] == '0')
		if ((int(q[i]) <= 0x0039 && int(q[i]) >= 0x0030) || (int(q[i]) <= 0x005A && int(q[i]) >= 0x0041))
		{
			p[k] = q[i];
			k++;
		}
		else if (q[i] == '+' || q[i] == '-')
		{
			while (!(stk[top] == '(' || stk[top]=='%'))
			{
				p[k] = pop_stk(stk, &top);
				k++;
			}
			push_stk(stk, &top, q[i], 100);
		}
		else if (q[i] == '%')
		{
			while (stk[top] != '(')
			{
				p[k] = pop_stk(stk, &top);
				k++;
			}
			push_stk(stk, &top, q[i], 100);
		}
		else if (q[i] == '*' || q[i] == '/')
		{
			while (stk[top] == '^')
			{
				p[k] = pop_stk(stk, &top);
				k++;
			}
			push_stk(stk, &top, q[i], 100);
		}
		else if (q[i] == '^')
		{
			push_stk(stk, &top, q[i], 100);
		}
		else if (q[i] == '(')
		{
			push_stk(stk, &top, q[i], 100);
		}
		else if (q[i] == ')')
		{
			while (stk[top] != '(')
			{
				p[k] = pop_stk(stk, &top);
				k++;
			}
			top--;
		}
	}
	cout << "\n\n";
	for (int i = 0;i < n;i++)
		if(p[i]!=-52)
			cout << "  " << p[i];
	cout << "\n\n";
	//cout << int(p[50]);
	
	//----------EVALUATING THE STRING-------------
	top = 0;
	int stk_i[100];
	for (int i = 0;i < n;i++)
	{
		if (int(p[i]) <= 0x005A && int(p[i]) >= 0x0041)
		{
			int val;
			cout << "\n"<<p[i]<<" = ";
			cin >> val;
			push_stk_i(stk_i, &top, val, 100);
		}
		else if (p[i] == '+')
		{
			int var1 = pop_stk_i(stk_i, &top);
			int var2 = pop_stk_i(stk_i, &top);
			int var3 = var2 + var1;
			push_stk_i(stk_i, &top, var3, 100);
		}
		else if (p[i] == '-')
		{
			int var1 = pop_stk_i(stk_i, &top);
			int var2 = pop_stk_i(stk_i, &top);
			int var3 = var2 - var1;
			push_stk_i(stk_i, &top, var3, 100);
		}
		else if (p[i] == '*')
		{
			int var1 = pop_stk_i(stk_i, &top);
			int var2 = pop_stk_i(stk_i, &top);
			int var3 = var2 * var1;
			push_stk_i(stk_i, &top, var3, 100);
		}
		else if (p[i] == '/')
		{
			int var1 = pop_stk_i(stk_i, &top);
			int var2 = pop_stk_i(stk_i, &top);
			int var3 = var2 / var1;
			push_stk_i(stk_i, &top, var3, 100);
		}
		else if (p[i] == '^')
		{
			int var1 = pop_stk_i(stk_i, &top);
			int var2 = pop_stk_i(stk_i, &top);
			int var3 = pow(var2 , var1);
			push_stk_i(stk_i, &top, var3, 100);
		}
		else if (p[i] == '%')
		{
			int var1 = pop_stk_i(stk_i, &top);
			int var2 = pop_stk_i(stk_i, &top);
			int var3 = var2 % var1;
			push_stk_i(stk_i, &top, var3, 100);
		}
	}
	cout << "\nThe evaluated result is: " << pop_stk_i(stk_i, &top) << "\n";
	return 0;

}