/*
Juan Bermudez
Dr Liyu Zhang
Project 2: Big O Notation and Running Times

The following program calculates the running time in milliseconds used for Big O notation.
*/

#include<iostream>
#include<cmath>
#include<chrono>


using namespace std; 

// (1)this function is linear of running time f(N) = O(N)
void One_linear(int&, int&);

// (2)this function is quadratic of running time f(N) = O(N^2)
void Two_quadratic(int&, int&);

//(3) this function is cubic of running time f(N) = O(N^3)
void Three_cubic(int&, int&); 

// (4)this recursive function is of quadratic of running time f(N) = O(N^2)
void Four_quadratic(int&, int&);

// (5)this recursive function is of running time f(N) = O(N^5)
void Five(int&, int&);

// (6)this recursive function is of running time f(N) = O(N^6)
void Six(int&, int&);

// (7)this recursive function is for efficient exponentiation
double Exponentiation(double&, int&);

// (8) this recursive function is for fast exponentiation
double FastExponentiation(double&, int&);

// (9) checks if a number is even or odd 
bool isEven(double); 

void menu(); 
void sizeMenu();

int main()
{
	int choice, size, n, sum=0;
	
	// generates a number from 1 to 3
	double x = (rand()% 3) + 1; 
	double product=0;
	
	// display the menu for the user to choose a recursive function
	menu();

	// enter a number for the choice you want to use 
	cin >> choice;

	// displays the menu to select a size of the number of iterations(recursion) 

	sizeMenu();

	// choose the iteration size btwn 100 - 10000
	cin >> size;

	// matching size of n to choice from sizeMenu
	switch (size)
	{
	case 1:
		n = 100;
		break;
	case 2: n = 1000;
		break;
	case 3: n = 10000;
		break;
	default: n = 0;
		break;
	}
	auto started = std::chrono::high_resolution_clock::now();
	switch(choice)
	{
		// (choice 1)
	case 1:
		
		One_linear(sum, n);

		break;
     
	   // (choice 2) 
	case 2:
		Two_quadratic(sum, n);
		break;

		// (choice 3) 
	case 3:
		Three_cubic(sum, n);
		break;

		// (choice 4) 
	case 4:
		Four_quadratic(sum, n);
		break;

		// (choice 5) 
	case 5:
		Five(sum, n);
		break;

		// (choice 6) 
	case 6:
		Six(sum, n);
		break;

		// (choice 7) 
	case 7:
		product = Exponentiation(x, n);
		break;

		// (choice 8) 
	case 8:
		product = FastExponentiation(x, n);
		break;

	default:
		cout << "Enter a valid choice.." << endl; 
		

	}
	// whichever choice you get will affect the sum, based on the recursive function you chose
	cout << "The sum is " << sum << endl;
	cout << "The result of the exponentiation was: " << product << endl;
	auto done = std::chrono::high_resolution_clock::now();
	cout << "The function took " << std::chrono::duration_cast<std::chrono::milliseconds>(done - started).count() << " milliseconds" << endl;

}
// choice(1)
void One_linear(int&sum, int&n)
{
	 sum = 0;
	for (int i = 0; i < n; ++i)
		++sum;

}
// choice(2)
void Two_quadratic(int&sum, int&n)
{
      sum = 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			++sum;

}
// choice(3)
void Three_cubic(int&sum, int&n)
{
	 sum = 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n * n; ++j)
			++sum;

}
// choice(4)
void Four_quadratic(int&sum, int&n)
{
	 sum = 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < i; ++j)
			++sum;

}

// choice(5)
void Five(int&sum, int&n)
{

	 sum = 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < i * i; ++j)
			for (int k = 0; k < j; ++k)
				++sum;

}

// choice (6)
void Six(int&sum, int&n)
{
	 sum = 0;
	for (int i = 1; i < n; ++i)
		for (int j = 1; j < i * i; ++j)
			if (j % i == 0)
				for (int k = 0; k < j; ++k)
					++sum;

}
// x is number generated 
// n is the number of times (n is the exponent) 
// choice (7)this recursive function is for regular exponentiation
double Exponentiation(double&x, int&n)
{
	// this loop raises a number to a power 
	double result = 1.0;

	for (int i = 1; i <= n; i++)
	{

		result = result*x;

	}

	return result; 
}

// choice (8) this recursive function is for fast exponentiation
double FastExponentiation(double&x, int&n)
{
	if (n == 0)
		return 1;
	if (n == 1)
		return x;
	if (isEven(n))
		return pow(x * x, n / 2);
	else
		return pow(x * x, n / 2);


}
// displays the menu to choose a recursive function
void menu()
{
	// choose a recursive function to calculate it's running time 
	cout << "Choose a recursive function to calculate it's running time" << endl; 

	cout << "1. This recursive function is linear of running time f(N) = O(N)" << endl;
	cout << "2. This recursive function is of quadratic of running time f(N) = O(N^2)" << endl;
	cout << "3. This recursive function is of cubic of running time f(N) = O(N^3)" << endl; 
	cout << "4. This recursive function is of quadratic of running time f(N) = O(N^2)" << endl; 
	cout << "5. This recursive function is of running time f(N) = O(N^5)" << endl; 
	cout << "6. This recursive function is of running time f(N) = O(N^6)" << endl; 
	cout << "7. This is a recursive function for regular exponentiation of type f(N)= O(N)" << endl;
	cout << "8. This is a recursive function for fast exponentiation of running time f(N)= O(log N)" << endl;
}

void sizeMenu()
{
	cout << "What size of n do you want?" << endl;
	cout << "1. 100" << "\n2. 1,000" << "\n3. 10,000" << endl;
}
bool isEven(double x)
{
	if (static_cast<int>(x) % 2 == 0)
		return true;
	else
		return false; 
}
