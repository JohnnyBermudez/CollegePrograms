#include <iostream>

#include <string>

#include <cstdlib>

#include<stack>

//Juan Bermudez
// 11/ 5/ 18 
// CMPE 3333 Project 4

using namespace std;

//this function takes in an Infix string expression and turns it into a postfix
//expression, it returns the postfix string expression

string InfixToPostfix(string);

// This function should receive the string passed from the Postfix function and evaluate the expression, returning true or false

char EvaluateBooleanPostFixExpression(string); 

//Function to return precedence of operators 
int hasHighPrecedence(char, char);

// The Operators perform the evaluation
bool IsOperator(char);

// Operands are T or F, they will be evaluated
bool IsOperand(char);



string InfixToPostfix(string expression)
{
	// initialize stack S
	stack<char> S;

	// initialize with empty string
	string postfix = ""; // initialize with empty string

// for i = 0 to n do the following cases (there is already an element in the first stack so it is for i =1 to jump it )
	for (int i = 0; i< expression.length(); i++)
	{
		// just in case a getline is used in main and u need to jump over a space, or a comma
		if (expression[i] == ' ' || expression[i] == ',') continue;

		else if (IsOperator(expression[i]))
		{
		// pop out the operators from the stack according to their precedence, greatest to least
			while (!S.empty() && S.top() != '(' && hasHighPrecedence(S.top(), expression[i]))
			{

				// The operators popped are according to their precedence,
				postfix += S.top();

				S.pop();
			}

			// the operators are pushed into the stack, parantheses will be popped later
			S.push(expression[i]);

		}

		// If the scanned character is an operand, add it to output string, Tokens.
		// all operands need to be copied to Tokens first
		else if (IsOperand(expression[i]))
		{

			postfix += expression[i];

		}
		
		// If the scanned character is an ‘(‘, push it to the stack.*** it wont be popped until the closing parentheses
		else if (expression[i] == '(')
		{

			S.push(expression[i]);

		}

		// If the scanned character is an ‘)’, pop both ()... eventually, but first all the operators need to be cppied into the output string
	
		else if (expression[i] == ')')
		{
			// If the scanned character is an ‘)’, pop both ()... eventually, but first all the operators need to be cppied into the output string
			while (!S.empty() && S.top() != '(') {
				postfix += S.top();

				S.pop();

			}
		S.pop();

		}
	}

	// at the end of the input, Pop all the remaining symbols from the stack to the end of the output
	while (!S.empty()) {
		postfix += S.top();
		S.pop();

	}
	// return the last element
	return postfix;

}

// Operands are T or F, they will be evaluated
bool IsOperand(char C)
{
	if (C == 'T' || C == 'F')
		return true;

	else
		return false;

}

// The Operators perform the evaluation
bool IsOperator(char C)
{

	if (C == '+' || C == '!' || C == '*')
		return true;
	else
	return false;

}

// check the assosiativity of operator

int IsRightAssociative(char op)
{
	if (op == '!') return true;

	else
	return false;

}

// get precedence of operator order in which to solve
int GetOperatorWeight(char op)
{
	int weight = -1;

	switch (op)

	{

	case '+':

		weight = 1;

		break;

	case '*':

		weight = 2;

		break;

	case '!':

		weight = 3;

		break;

	}

	return weight;

}

// return true if op1 has high precedence than op2
int hasHighPrecedence(char op1, char op2)

{

	int op1Weight = GetOperatorWeight(op1);

	int op2Weight = GetOperatorWeight(op2);

	if (op1Weight == op2Weight)

	{

		if (IsRightAssociative(op1)) return false;

		else return true;

	}

	return op1Weight > op2Weight ? true : false;
}

// This function should receive the string passed from the Postfix function and evaluate the expression, returning true or false
char EvaluateBooleanPostFixExpression(string x)
{
	// length of expression
	int n = x.length(); // length of expression

	char Op1; char Op2; char symbol;

	// initialize a stack to be empty
	stack<int>Y;

	// for i = 0 to length n of the Expression do
	for (int i = 0; i < n; i++)
	{
		// if character is an operand then push it onto the stack
		if (IsOperand(x[i]))
		{

			Y.push(x[i]);

		}

		/*else if the character is an operator, pop two items n1 and n2 from the
		stack, calculate the op of n1 and n2, and then push the result into the stack*/

		else if (IsOperator(x[i])) {

			switch (x[i]) {

				// case when character is NOT then pop one element from stack and push it's negation (i.e if !T, then push F into the stack)
			case '!':

				// stacks are last in first out, so Operator1 is inserted in the end of the stack
				// top then pushes the operator into the last element of the stack

				Op1 = Y.top();

				Y.pop();

				// evaluate the NOT operation,k
				if (Op1 == 'T')
					Y.push('F');

				// and then push the result into the stack

				else
					Y.push('T');

				break;

				// case for AND when * is encountere
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

				// in case of error
			default: exit(-1); break;

			}

		}

	}

	// output the only remaining item in the stack, the answer to the expression
	return Y.top();

}