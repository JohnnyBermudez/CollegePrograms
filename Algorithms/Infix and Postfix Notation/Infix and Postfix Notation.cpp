#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include<chrono>
#include<stack>
#include "EvalBool.h"

//Juan Bermudez
// 11/ 5/ 18 
// CMPE 3333 Project 4
// If program does not run, change the file name to project4.cpp

using namespace std;


string rand_gen_logExp(int);

int main()
{
	const int a = 100; 
	const int b = 1000;
	const int c = 10000; 

	// genererate a random string expression
	auto started1 = std::chrono::high_resolution_clock::now();
	string expressionA = rand_gen_logExp(a) ;
	auto done1 = std::chrono::high_resolution_clock::now();

	// convert the infix expression to postfix
	auto started2 = std::chrono::high_resolution_clock::now();
	string postfixA = InfixToPostfix(expressionA);
	auto done2 = std::chrono::high_resolution_clock::now();

	// evaluate the postfix expression
	auto started3 = std::chrono::high_resolution_clock::now();
	char A = EvaluateBooleanPostFixExpression(postfixA);
	auto done3 = std::chrono::high_resolution_clock::now();
	
	cout << endl << endl; 

	
	cout << "\tRunning Times for 100 inputs:" << endl;
	cout << " Generate A String Expression:  " << std::chrono::duration_cast<std::chrono::microseconds>(done1 - started1).count() << " microseconds" << endl;
	cout << " Convert Infix Expression To Postfix: " << std::chrono::duration_cast<std::chrono::microseconds>(done2 - started2).count() << " microseconds" << endl;
	cout << " Evaluate Postfix Expression " << std::chrono::duration_cast<std::chrono::microseconds>(done3 - started3).count() << " microseconds" << endl;

	cout << endl; 
	/*
	cout << " Input = " << expressionA << endl;

	cout << " Postfix = " << postfixA << "\n";

	cout << " Output = " << A << "\n\n";
	*/

	// genererate a random string expression
	auto started4 = std::chrono::high_resolution_clock::now();
	string expressionB = rand_gen_logExp(b);
	auto done4 = std::chrono::high_resolution_clock::now();

	// convert the infix expression to postfix
	auto started5 = std::chrono::high_resolution_clock::now();
	string postfixB = InfixToPostfix(expressionB);
	auto done5 = std::chrono::high_resolution_clock::now();

	// evaluate the postfix expression
	auto started6 = std::chrono::high_resolution_clock::now();
	char B = EvaluateBooleanPostFixExpression(postfixB);
	auto done6 = std::chrono::high_resolution_clock::now();

	
	

	cout << "\tRunning Times for 1000 inputs:" << endl;
	cout << " Generate A String Expression:  " << std::chrono::duration_cast<std::chrono::microseconds>(done4 - started4).count() << " microseconds" << endl;
	cout << " Convert Infix Expression To Postfix: " << std::chrono::duration_cast<std::chrono::microseconds>(done5 - started5).count() << " microseconds" << endl;
	cout << " Evaluate Postfix Expression " << std::chrono::duration_cast<std::chrono::microseconds>(done6 - started6).count() << " microseconds" << endl;
	cout << endl;
	/*
	cout << " Input = " << expressionB << endl;

	cout << " Postfix = " << postfixB << "\n";

	cout << " Output = " << B << "\n\n";
	*/

	// genererate a random string expression
	auto started7 = std::chrono::high_resolution_clock::now();
	string expressionC = rand_gen_logExp(c);
	auto done7 = std::chrono::high_resolution_clock::now();

	// convert the infix expression to postfix
	auto started8 = std::chrono::high_resolution_clock::now();
	string postfixC = InfixToPostfix(expressionC);
	auto done8 = std::chrono::high_resolution_clock::now();

	// evaluate the postfix expression
	auto started9 = std::chrono::high_resolution_clock::now();
	char C = EvaluateBooleanPostFixExpression(postfixC);
	auto done9 = std::chrono::high_resolution_clock::now();
	
	
	cout << "\tRunning Times for 10000 inputs:" << endl;
	cout << " Generate A String Expression:  " << std::chrono::duration_cast<std::chrono::microseconds>(done7 - started7).count() << " microseconds" << endl;
	cout << " Convert Infix Expression To Postfix: " << std::chrono::duration_cast<std::chrono::microseconds>(done8 - started8).count() << " microseconds" << endl;
	cout << " Evaluate Postfix Expression " << std::chrono::duration_cast<std::chrono::microseconds>(done9 - started9).count() << " microseconds" << endl;
	cout << endl;
	/*
	cout << " Input = " << expressionC << endl;

	cout << " Postfix = " << postfixC << "\n";

	cout << " Output = " << C << "\n\n";
	*/
	
}

string rand_gen_logExp(int n) {

	if (n <= 0)
		return "";

	//possible symbols in the expression

	string symbols = "FT()!*+";

	//possible symbols after each current symbol

	string succ[] = { "*+)","*+)", "!FT", "*+)", "FT(!", "FT(!", "FT(!" };

	//Ouput string initialized;

	string logical_exp = "";

	//number of left apparantheses generated so far

	int num_of_lp = 0;

	//initializz first symbol of the output
	char first_symbol = ' ';
	//randomly generate first symbol in the output

	//seed for rand

	srand(time(0));

	switch (rand() % 4)
	{
	case 0: first_symbol = 'F'; break;

	case 1: first_symbol = 'T'; break;

	case 2: first_symbol = '!'; break;

	case 3: first_symbol = '('; num_of_lp++;

		break;
	}

	logical_exp += first_symbol;

	// The last symbol generated
	char last_symbol = first_symbol;
	// The main loop that generates the rest of the expression
	for (int i = 1; i<n - num_of_lp; i++)
	{
		//string s = succ[symbols.indexOf(last_symbol)];

		string s = succ[symbols.find(last_symbol)];

		char next_symbol;

		bool again;
		// genrating tahe next symbol in the expression and
		// make sure that it conforms to format of loogical expressions
		do
		{
			again = false;

			next_symbol = s.at(rand() % (s.length()));

			switch (next_symbol)
			{
			case ')': // All parantheses seen so far matched

					  // ) is not allowed for next symbol

				if (num_of_lp == 0)
				{
					again = true;

				}

				else
					num_of_lp--;
				break;

			case '(': num_of_lp++;
				break;

			}

		} while (again);

		logical_exp += next_symbol;

		last_symbol = next_symbol;

	}

	// check if the last symbol is an operator and hence need an operand
	if ((last_symbol == '(' || last_symbol == '*' || last_symbol == '+' || last_symbol == '!'))

		logical_exp += rand() % 2 == 0 ? 'F' : 'T';

	// adding necessary closing )'s
	for (int i = 0; i<num_of_lp; i++)

		logical_exp += ')';

	return logical_exp;

}
