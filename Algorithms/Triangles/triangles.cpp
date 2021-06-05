#include<cmath>
#include<cstdlib>
#include<ctime>
#include<iostream>

/* 
Juan Bermudez
 9/ 10/ 18
 Project 1: Triangles
 CMPE 3333
 
 
 The following program generates a random number of triangles, compares each triangle in order to find the max area and max perimeter from the bunch.
*/
using namespace std;
class Triangle
{
public:
	Triangle() {
		// this constructor function sets the 3 side lengths to 0
		// this is the default constructor

		sideA = 0;
		sideB = 0;
		sideC = 0;
	}

	Triangle(float a, float b, float c)
	{
		// this constructor assigns values to the side lengths of the triangle a, b, and c.
		// we also pass the funtion getAngle to calculate the angles of the triangle
		// so the sides and angles can formally have values

		//  constructor with side length parameters
		sideA = a;
		sideB = b;
		sideC = c;

		// this will calculate the angles
		calculateAngle();
	}

	float *getSides()
	{
		// this function allocates the memory of the array where the sides of the triangle are stored 
		// by using a pointer for reference.
		//this function will also locate the array where the sides of the triangle are pointed to

		float *a = new float[3];
		a[0] = sideA;
		a[1] = sideB;
		a[2] = sideC;

		return a;
	}
	float *getAngles()
	{
		//  Similar to the function getSides, this function will also be pointed to in memory.
		// The contents of the array will also be allocated and stored in memory

		// the method returns the array with the values of the sides
		// a pointer allocates the memory where the array is located
		float *a = new float[3];


		a[0] = sideA;
		a[1] = sideB;
		a[2] = sideC;

		return a;
	}


	// The class object Triangle, x, is passed by reference to the function getPerimeter
	//

	float getPerimeter(Triangle x)
	{

		// the memory allocation of the sides are pointed to so they can be accessed
		float *sides = new float[3];

		// the getSides function stores the array in sides
		sides = x.getSides();

		// in order to get the perimeter of the triangle, the array's contents are added.
		return sides[0] + sides[1] + sides[2];

	}

	//method will calculate the area of triangle

	float getArea(Triangle x)
	{

		float *sides = new float[3];

		sides = x.getSides();

		// perform calculations to get Area
		float sideA = sides[0], sideB = sides[1], sideC = sides[2];

		float s = (sideA + sideB + sideC) / 2;

		float Area = sqrt((s*(s - sideA)*(s - sideB)*(s - sideC)));

		return Area;

	}

private:
	float sideA, sideB, sideC; // variables that store the side lengths of the triangle 

	float angleA, angleB, angleC; // variables that sore the angles of the triangle

	void calculateAngle()
	{
		// Function to calculate the angles of the triangle.
		// The semiperimeter is calculated using the sidelengths of the triangle using Heron's formula
		// The area of the triangleis calculated using Herons formula. The semiperimeter is needed  to calculate area
		// The circumradius of the triangle is calculated here. The circumradius is needed to calculate the angles
		// The angles are calculated using the extended law of sines. They are multiplied by (180/pi) to convert the radians to degrees


		float pi = acos(-1); // sets pi to 3.14159

							 //Herons formula for half of the half perimeter(or semiperimeter) of a triangle
							 // the formula calls for the lengths of sides a,b, and c added and divided by 2
		float s = (sideA + sideB + sideC) / 2;

		// the area of a triangle using the semiperimeter, from Herons formula
		float area = sqrt((s*(s - sideA)*(s - sideB)*(s - sideC)));

		// this formula calculates the circumradius R, of a triangle
		float R = (sideA*sideB*sideC) / (4 * area);

		// The angles are calculated using the formulas for extended laws of sine theorem
		// They include the circumradius of the triangle
		// The angles are derived using the arcsine of the equation

		angleA = asin(sideA / (2 * R)); // might use 180/ pi if needed to convert to degrees
		angleB = asin(sideB / (2 * R));
		angleC = asin(sideC / (2 * R));

	}
};

float getPerimeter(Triangle x)
{

	// the memory allocation of the sides are pointed to so they can be accessed
	float *sides = new float[3];

	// the getSides function stores the array in sides
	sides = x.getSides();

	// in order to get the perimeter of the triangle, the array's contents are added.
	return sides[0] + sides[1] + sides[2];

}

//method will calculate the area of triangle

float getArea(Triangle x)
{

	float *sides = new float[3];

	sides = x.getSides();

	// perform calculations to get Area
	float sideA = sides[0], sideB = sides[1], sideC = sides[2];

	float s = (sideA + sideB + sideC) / 2;

	float Area = sqrt((s*(s - sideA)*(s - sideB)*(s - sideC)));

	return Area;

}



int main()
{
	srand(time(0)); // random generator starting at time 0

					// use the rand function to create a number in the array to show the number of triangles generated

	int array_length = rand() % 30 + 5;

	cout << "The total number of triangles generated randomly are: " << array_length << " \n\n";

	// The for loop will generate sides for each triangle and store them in the Triangle object
	// to initialize each array

	Triangle *array = new Triangle[array_length];

	int count = 0;

	for (int i = 1; i < array_length; i++)
	{
		float sideA = rand() % 5 + 2;
		float sideB = rand() % 8 + 2;
		float sideC = rand() % 9 + 2;

		Triangle x(sideA, sideB, sideC); // triangle function with parameters
		array[count++] = x;

	}

	float maxPerimeter = -1;
	float maxArea = -1;

	Triangle maxPerimeterTriangle;
	Triangle maxAreaTriangle;

	// loop through the Triangle array to calculate the perimeter and the area of the largest Triangle
	for (int i = 0; i < array_length; i++)
	{
		Triangle x = array[i];

		float Area = getArea(x);  // the contents of Triangle x will be calculated in the getArea function and stored in Area

		float Perimeter = getPerimeter(x); // the contents of Triangle x are calculated and stored in Perimeter

										   // condition that must be true to  store values of the Area
		if (Area > maxArea)
		{
			// the contents of the largest area will be stored in an array
			maxArea = Area;
			maxAreaTriangle = array[i];

		}

		if (Perimeter > maxPerimeter)
		{
			maxPerimeter = Perimeter;
			maxPerimeterTriangle = array[i];
		}
	}


	cout << " The max area is: " << maxArea << endl;
	cout << "The max perimeter is: " << maxPerimeter << endl;

	return 0;

}


