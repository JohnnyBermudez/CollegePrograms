#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include<chrono>
#include<stack>

using namespace std;

//Function to return precedence of operators 
int prec(char c)
{
	if (c == '!')
		return 3;
	else if (c == '*')
		return 2;
	else if (c == '+')
		return 1;
	else
		return -1;
}

/*
this function takes in an Infix string expression and turns it into a postfix
expression, it returns the postfix string expression
*/ 
string InfixToPostfix(string Expression)
{
	// initialize stack S 
	stack<char>S;
	// this will serve as the first element of the stack
	st.push('L');

	// initialize output string Tokens to be empty
	string Tokens;

	// for i = 0 to n do the following cases (there is already an element in the first stack so it is for i =1 to jump it ) 
	for (int i = 0; i <Expression.length(); i++)
	{
		// process the array of Expression[1..n]

		// If the scanned character is an operand, add it to output string, Tokens.
		// all operands need to be copied to Tokens first
		if ((s[i] == 'T') || (s[i] == 'F'))
			Tokens += s[i];

		// If the scanned character is an ‘(‘, push it to the stack.*** it wont be popped until the closing parenthese
		else if (s[i] == '(')

			st.push('(');

		// If the scanned character is an ‘)’, pop both ()... eventually, but first all the operators need to be cppied into the output string
		else if (s[i] == ')')
		{
			//push all operators of the string to to the stack until an ‘(‘ is encountered.
			while (st.top() != 'L' && st.top() != '(')
			{

				// is it a (? No? then pop the operator
				char c = st.top();
				st.pop();

				//and put it in Tokens
				Tokens += c;
			}
			// when the parentheses close then pop them from the stack
			if (st.top() == '(')
			{
				char c = st.top();
				st.pop();
			}
		}	
		else {
			// pop out the operators from the stack according to their precedence, greatest to least
			// this is case II in the pseudocode from the powerpoint slide 32
						while (st.top() != 'L' && prec(s[i]) <= prec(st.top()))
			{
				char c = st.top();
				st.pop();

				// The operators popped are according to their precedence, add the operators popped into the ouput string
				Tokens += c;
			}
			st.push(s[i]);
		}

	}

	// at the end of the input, Pop all the remaining  symbols from the stack to the end of the output
	while (st.top() != 'L')
	{
		char c = st.top();
		st.pop();
		Tokens += c;
	}

	cout << Tokens << endl;

	return Tokens;
}


// This function should receive the string passed from the Postfix function and evaluate the expression, returning true or false
char EvaluateBooleanPostFixExpression(string x)
{
	// length of expression
	int n = x.length();

	char Op1, Op2, symbol;

	// initialize a stack to be empty
	stack<int>Y;


	// for i = 0 to length n of the Expression do

	for (int i = 0; i < n; i += 2) {

		/// if character is an operand(T or F)  then push it into the stack as it is scanned
		if (IsOperand(n[i]))
		{

			// push character in the stack
			Y.push(x[i]);

		}

		/*else if the character is an operator, pop two items n1 and n2 from the
		stack, calculate the op of n1 and n2, and then push the result into the stack*/

		else if (IsOperator(x[i]))
		{
			switch (x[i])
			{

				// case when character is NOT then pop one element from stack and push it's negation (i.e if !T, then push F into the stack)
			case '!':

				// stacks are last in first out, so Operator1 is inserted in the end of the stack
				// top then pushes the operator into the last element of the stack
				Op1 = Y.top();

				// pop the item 
				Y.pop();

				// evaluate the NOT operation,k
				if (Op1 == 'T')
					Y.push('F');
				//  and then push the result into the stack
				else
					Y.push('T');

				break;

				// case for AND when * is encountered
			case '*':
				// pop n1 and n2 from the stack
				Op1 = Y.top();

				Y.pop();

				Op2 = Y.top();

				Y.pop();

				// evaluate using the Truth operation for AND, and then push the result into the stack
				if (Op1 == 'T' && Op2 == 'T')
					Y.push('T');

				else
					Y.push('F');

				break;

				// Case for OR when + is encountered
			case '+':
				// pop n1 and n2 from the stack
				Op1 = Y.top();

				Y.pop();

				Op2 = Y.top();

				Y.pop();

				// evaluate the OR Truth operation on the popped elements, then push the result back into the stack
				if (Op1 == 'F' && Op2 == 'F')

					Y.push('F');

				else

					Y.push('T');

				break;
				// if there are no sufficient operands  report error and exit
			default: exit(-1); break; // incase of error


			}

		}

	}

	// output the only remaining item in the stack, the answer to the expression
	return Y.top();
}



// Operands are T or F, they will be evaluated
bool IsOperand(char Operand)
{
if(Operand == 'T' && Operand == 'F')
return true; 

else
return false; 
}

// The Operators perform the evaluation
bool IsOperator(char Operator)
{
if(Operator == '!' && Operator == '*' && Operator =='+')
return true; 

else 
return false; 

}