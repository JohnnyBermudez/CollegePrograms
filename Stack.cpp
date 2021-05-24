#include <iostream>

using namespace std; 
#define MAX 1000



/* C++ program to implement basic stack
operations */



class Stack
{
	int top;
public:
	char a[MAX];    //Maximum size of Stack 

	Stack()
	{ top = -1; }
	

	bool Stack::push(char x)
	{
		if (top >= (MAX - 1))
		{
			cout << "Stack Overflow";
			return false;
		}
		else
		{
			a[++top] = x;
			cout << x << " pushed into stack\n";
			return true;
		}
	}

	char Stack::pop()
	{
		if (top < 0)
		{
			cout << "Stack Underflow";
			return 0;
		}
		else
		{
			char x = a[top--];
			return x;
		}
	}

	bool Stack::isEmpty()
	{
		return (top < 0);
	}
}; 