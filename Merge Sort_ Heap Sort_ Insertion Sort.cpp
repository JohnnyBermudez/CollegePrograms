/*
Juan Bermudez
CMPE 3333
10/18/2018 
Project 3 
Copyrights under University of Texas Rio Grande Valley
*/

#include <iostream>
#include <ctime>
#include<chrono>
#include<cstdlib>
#include<cmath>
#include <algorithm> // for function swap

/*most of the functions return counter, counter is the number of comparisons made in the
sorting algorithm */
using namespace std;

int InsertionSort(int[], int);
int MergeSort(int[], int, int);
int HeapSort(int[], int);
int QuickSort(int[], int, int);
int MERGE(int[], int, int, int);
int PARTITION(int[], int, int, int*);
int MAX_HEAPIFY(int[], int, int);
int BUILD_MAX_HEAP(int[], int);
void RevereseArray(int[], int, int);

int main()
{

	int c1, c2, c3, c4, c5, c6; // number of comparisons made in an algorithm

								// these were the max values that were permitted without giving error
	const int size1 = 1000;
	const int size2 = 10000;
	const int size3 = 100000;


	srand((unsigned)time(0));

	// pointers create array because value is changing
	int* RandomArray1;
	RandomArray1 = new int[size1];
	int* RandomArray2;
	RandomArray2 = new int[size2];
	int* RandomArray3;
	RandomArray3 = new int[size3];


	for (int i = 0; i < size1; i++)
	{
		// fill the arrays with random numbers from 1 - 1000
		RandomArray1[i] = rand() % 100;
	}
	for (int i = 0; i < size2; i++)
	{
		RandomArray2[i] = rand() % 100;
	}
	for (int i = 0; i <size3; i++)
	{
		RandomArray3[i] = rand() % 100;
	}

	cout << "Insertion Sort: " << endl << endl;

	// comparisons and running times for the insertion sort algorithm
	auto started1 = std::chrono::high_resolution_clock::now();
	c1 = InsertionSort(RandomArray1, size1);
	auto done1 = std::chrono::high_resolution_clock::now();
	cout << "Random Array 1, Running Time: " << std::chrono::duration_cast<std::chrono::microseconds>(done1 - started1).count() << " microseconds" << endl;
	cout << "Total Comparisons: " << c1 << endl << endl;

	auto started2 = std::chrono::high_resolution_clock::now();
	c2 = InsertionSort(RandomArray2, size2);
	auto done2 = std::chrono::high_resolution_clock::now();
	cout << "Random Array 2, Running Time: " << std::chrono::duration_cast<std::chrono::microseconds>(done2 - started2).count() << " microseconds" << endl;
	cout << "Total Comparisons: " << c2 << endl << endl;

	auto started3 = std::chrono::high_resolution_clock::now();
	c3 = InsertionSort(RandomArray2, size3);
	auto done3 = std::chrono::high_resolution_clock::now();
	cout << "Random Array 3, Running Time: " << std::chrono::duration_cast<std::chrono::microseconds>(done3 - started3).count() << " microseconds" << endl;
	cout << "Total Comparisons: " << c3 << endl << endl;

	// reverses the contents of the array from largest to smallest
	RevereseArray(RandomArray1, 0, size1);
	RevereseArray(RandomArray2, 0, size2);
	RevereseArray(RandomArray3, 0, size3);


	cout << "The arrays are now reversed, the new comparison count and running times are below for Insertion Sort: " << endl << endl;
	// repeat the order of the three arrays 
	// calculate time and comparisons for Random Array 1
	started1 = std::chrono::high_resolution_clock::now();
	c1 = InsertionSort(RandomArray1, size1);
	done1 = std::chrono::high_resolution_clock::now();
	cout << "Random Array 1, Running Time:  " << std::chrono::duration_cast<std::chrono::microseconds>(done1 - started1).count() << " microseconds" << endl;
	cout << "Total Comparisons: " << c1 << endl << endl;

	// calculate time and comparisons for Random Array 2
	started2 = std::chrono::high_resolution_clock::now();
	c2 = InsertionSort(RandomArray2, size2);
	done2 = std::chrono::high_resolution_clock::now();
	cout << "Random Array 2, Running Time:  " << std::chrono::duration_cast<std::chrono::microseconds>(done2 - started2).count() << " microseconds" << endl;
	cout << "Total Comparisons: " << c2 << endl << endl;

	// calculate time and comparisons for Random Array 3
	started3 = std::chrono::high_resolution_clock::now();
	c3 = InsertionSort(RandomArray3, size3)*-1;
	done3 = std::chrono::high_resolution_clock::now();
	cout << "Random Array 3, Running Time:  " << std::chrono::duration_cast<std::chrono::microseconds>(done3 - started3).count() << " microseconds" << endl;
	cout << "Total Comparisons:  " << c3 << endl << endl;

	int* RandomArray4;
	RandomArray4 = new int[size1];
	int* RandomArray5;
	RandomArray5 = new int[size2];
	int* RandomArray6;
	RandomArray6 = new int[size3];


	for (int i = 0; i < size1; i++)
	{
		// fill the arrays with random numbers from 1 - 1000
		RandomArray4[i] = rand() % 100;
	}
	for (int i = 0; i < size2; i++)
	{
		RandomArray5[i] = rand() % 100;
	}
	for (int i = 0; i <size3; i++)
	{
		RandomArray6[i] = rand() % 100;
	}

	cout << "Merge Sort: " << endl << endl;

	// comparisons and running times for the insertion sort algorithm
	auto started4 = std::chrono::high_resolution_clock::now();
	c4 = MergeSort(RandomArray4, 0, size1);
	auto done4 = std::chrono::high_resolution_clock::now();
	cout << "Random Array 1, Running Time: " << std::chrono::duration_cast<std::chrono::microseconds>(done4 - started4).count() << " microseconds" << endl;
	cout << "Total Comparisons: " << c4 << endl << endl;

	auto started5 = std::chrono::high_resolution_clock::now();
	c5 = MergeSort(RandomArray5, 0, size2);
	auto done5 = std::chrono::high_resolution_clock::now();
	cout << "Random Array 2, Running Time: " << std::chrono::duration_cast<std::chrono::microseconds>(done5 - started5).count() << " microseconds" << endl;
	cout << "Total Comparisons: " << c5 << endl << endl;

	auto started6 = std::chrono::high_resolution_clock::now();
	c6 = MergeSort(RandomArray6, 0, size3);
	auto done6 = std::chrono::high_resolution_clock::now();
	cout << "Random Array 3, Running Time: " << std::chrono::duration_cast<std::chrono::microseconds>(done6 - started6).count() << " microseconds" << endl;
	cout << "Total Comparisons: " << c6 << endl << endl;

	// reverses the contents of the array from largest to smallest
	RevereseArray(RandomArray4, 0, size1);
	RevereseArray(RandomArray5, 0, size2);
	RevereseArray(RandomArray6, 0, size3);


	cout << "The arrays are now reversed, the new comparison count and running times are below for Merge Sort: " << endl << endl;

	started4 = std::chrono::high_resolution_clock::now();
	c4 = MergeSort(RandomArray4, 0, size1);
	done4 = std::chrono::high_resolution_clock::now();
	cout << "Random Array 1, Running Time: " << std::chrono::duration_cast<std::chrono::microseconds>(done4 - started4).count() << " microseconds" << endl;
	cout << "Total Comparisons: " << c4 << endl << endl;

	started5 = std::chrono::high_resolution_clock::now();
	c5 = MergeSort(RandomArray5, 0, size2);
	done5 = std::chrono::high_resolution_clock::now();
	cout << "Random Array 2, Running Time: " << std::chrono::duration_cast<std::chrono::microseconds>(done5 - started5).count() << " microseconds" << endl;
	cout << "Total Comparisons: " << c5 << endl << endl;

	started6 = std::chrono::high_resolution_clock::now();
	c6 = MergeSort(RandomArray6, 0, size3);
	done6 = std::chrono::high_resolution_clock::now();
	cout << "Random Array 3, Running Time: " << std::chrono::duration_cast<std::chrono::microseconds>(done6 - started6).count() << " microseconds" << endl;
	cout << "Total Comparisons: " << c6 << endl << endl;

	int c7, c8, c9;
	int* RandomArray7;
	RandomArray7 = new int[size1];
	int* RandomArray8;
	RandomArray8 = new int[size2];
	int* RandomArray9;
	RandomArray9 = new int[size3];


	for (int i = 0; i < size1; i++)
	{
		// fill the arrays with random numbers from 1 - 1000
		RandomArray7[i] = rand() % 100;
	}
	for (int i = 0; i < size2; i++)
	{
		RandomArray8[i] = rand() % 100;
	}
	for (int i = 0; i <size3; i++)
	{
		RandomArray9[i] = rand() % 100;
	}

	cout << "Heap Sort: " << endl << endl;

	// comparisons and running times for the insertion sort algorithm
	auto started7 = std::chrono::high_resolution_clock::now();
	c7 = HeapSort(RandomArray7, size1);
	auto done7 = std::chrono::high_resolution_clock::now();
	cout << "Random Array 1, Running Time: " << std::chrono::duration_cast<std::chrono::microseconds>(done7 - started7).count() << " microseconds" << endl;
	cout << "Total Comparisons: " << c7 << endl << endl;

	auto started8 = std::chrono::high_resolution_clock::now();
	c8 = HeapSort(RandomArray8, size2);
	auto done8 = std::chrono::high_resolution_clock::now();
	cout << "Random Array 2, Running Time: " << std::chrono::duration_cast<std::chrono::microseconds>(done8 - started8).count() << " microseconds" << endl;
	cout << "Total Comparisons: " << c8 << endl << endl;

	auto started9 = std::chrono::high_resolution_clock::now();
	c9 = HeapSort(RandomArray9, size3);
	auto done9 = std::chrono::high_resolution_clock::now();
	cout << "Random Array 3, Running Time: " << std::chrono::duration_cast<std::chrono::microseconds>(done9 - started9).count() << " microseconds" << endl;
	cout << "Total Comparisons: " << c9 << endl << endl;

	// reverses the contents of the array from largest to smallest
	RevereseArray(RandomArray7, 0, size1);
	RevereseArray(RandomArray8, 0, size2);
	RevereseArray(RandomArray9, 0, size3);


	cout << "The arrays are now reversed, the new comparison count and running times are below for Heap Sort: " << endl << endl;

	started7 = std::chrono::high_resolution_clock::now();
	c7 = HeapSort(RandomArray7, size1);
	done7 = std::chrono::high_resolution_clock::now();
	cout << "Random Array 1, Running Time: " << std::chrono::duration_cast<std::chrono::microseconds>(done7 - started7).count() << " microseconds" << endl;
	cout << "Total Comparisons: " << c7 << endl << endl;

	started8 = std::chrono::high_resolution_clock::now();
	c8 = HeapSort(RandomArray8, size2);
	done8 = std::chrono::high_resolution_clock::now();
	cout << "Random Array 2, Running Time: " << std::chrono::duration_cast<std::chrono::microseconds>(done8 - started8).count() << " microseconds" << endl;
	cout << "Total Comparisons: " << c8 << endl << endl;

	started9 = std::chrono::high_resolution_clock::now();
	c9 = HeapSort(RandomArray9, size3);
	done9 = std::chrono::high_resolution_clock::now();
	cout << "Random Array 3, Running Time: " << std::chrono::duration_cast<std::chrono::microseconds>(done9 - started9).count() << " microseconds" << endl;
	cout << "Total Comparisons: " << c9 << endl << endl;

	int c10, c11, c12;
	int* RandomArray10;
	RandomArray10 = new int[100];
	int* RandomArray11;
	RandomArray11 = new int[1000];
	int* RandomArray12;
	RandomArray12 = new int[10000];


	for (int i = 0; i < 100; i++)
	{
		// fill the arrays with random numbers from 1 - 1000
		RandomArray10[i] = rand() % 100;
	}
	for (int i = 0; i < 1000; i++)
	{
		RandomArray11[i] = rand() % 100;
	}
	for (int i = 0; i <10000; i++)
	{
		RandomArray12[i] = rand() % 100;
	}

	cout << "Quick Sort: " << endl << endl;

	// comparisons and running times for the insertion sort algorithm
	auto started10 = std::chrono::high_resolution_clock::now();
	c10 = QuickSort(RandomArray10, 0, 100);
	auto done10 = std::chrono::high_resolution_clock::now();
	cout << "Random Array 1, Running Time: " << std::chrono::duration_cast<std::chrono::microseconds>(done10 - started10).count() << " microseconds" << endl;
	cout << "Total Comparisons: " << c10 << endl << endl;

	auto started11 = std::chrono::high_resolution_clock::now();
	c11 = QuickSort(RandomArray11, 0, 1000);
	auto done11 = std::chrono::high_resolution_clock::now();
	cout << "Random Array 2, Running Time: " << std::chrono::duration_cast<std::chrono::microseconds>(done11 - started11).count() << " microseconds" << endl;
	cout << "Total Comparisons: " << c11 << endl << endl;

	auto started12 = std::chrono::high_resolution_clock::now();
	c12 = QuickSort(RandomArray12, 0, 10000);
	auto done12 = std::chrono::high_resolution_clock::now();
	cout << "Random Array 3, Running Time: " << std::chrono::duration_cast<std::chrono::microseconds>(done12 - started12).count() << " microseconds" << endl;
	cout << "Total Comparisons: " << c12 << endl << endl;

	// reverses the contents of the array from largest to smallest
	RevereseArray(RandomArray10, 0, 100);
	RevereseArray(RandomArray11, 0, 1000);
	RevereseArray(RandomArray12, 0, 10000);

	cout << "The arrays are now reversed, the new comparison count and running times are below for Quick Sort: " << endl << endl;

	started10 = std::chrono::high_resolution_clock::now();
	c10 = QuickSort(RandomArray10, 0, 100);
	done10 = std::chrono::high_resolution_clock::now();
	cout << "Random Array 1, Running Time: " << std::chrono::duration_cast<std::chrono::microseconds>(done10 - started10).count() << " microseconds" << endl;
	cout << "Total Comparisons: " << c10 << endl << endl;

	started11 = std::chrono::high_resolution_clock::now();
	c11 = QuickSort(RandomArray11, 0, 1000);
	done11 = std::chrono::high_resolution_clock::now();
	cout << "Random Array 2, Running Time: " << std::chrono::duration_cast<std::chrono::microseconds>(done11 - started11).count() << " microseconds" << endl;
	cout << "Total Comparisons: " << c11 << endl << endl;

	started12 = std::chrono::high_resolution_clock::now();
	c12 = QuickSort(RandomArray12, 0, 10000);
	done12 = std::chrono::high_resolution_clock::now();
	cout << "Random Array 3, Running Time: " << std::chrono::duration_cast<std::chrono::microseconds>(done12 - started12).count() << " microseconds" << endl;
	cout << "Total Comparisons: " << c12 << endl << endl;

	system("pause"); 
	return 0;

}


int InsertionSort(int arr[], int n)
{

	// n is the length of the array

	// number of comparisons counter, it increments with every comparisonsa
	int counter = 0;
	int i, key, j;

	for (j = 2; j < n; j++)
	{
		key = arr[j];

		i = j - 1;

		/* Move elements of arr[0..i-1], that are
		greater than key, to one position ahead
		of their current position */

		while (i >= 0 && arr[i] > key)
		{

			arr[i + 1] = arr[i];
			// counts the number of comparisons in insertion sort
			counter++;
			i = i - 1;

		}


		arr[i + 1] = key;
	}

	return counter;



}

int MergeSort(int arr[], int p, int r)
{
	// comparison counter for MergeSort
	int counter = 0;
	int q;

	if (p < r)
	{
		q = (p + r) / 2;

		MergeSort(arr, p, q);
		MergeSort(arr, q + 1, r);

		// returns the counter sum from the function merge
		counter = counter + MERGE(arr, p, q, r);

	}
	return counter;
}

int MERGE(int arr[], int p, int q, int r)

{


	// comparison counter for Merge 
	int counter = 0;

	// pointers create array because value is changing
	int* Larray;
	int* Rarray;



	int n1 = q - p + 1;
	int n2 = r - q;

	int i, j;

	// assign new dynamic value, use pointers when u do not know the size

	Larray = new int[n1];
	Rarray = new int[n2];

	// this is not a nested loop

	for (int i = 0; i < n1; i++)
		Larray[i] = arr[p + i];

	for (int j = 0; j < n2; j++)
		Rarray[j] = arr[q + j + 1];

	i = 0;
	j = 0;

	int k = p;

	for (; i < n1 && j<n2;)
	{
		if (Larray[i] <= Rarray[j])

		{
			// comparisons of MERGE
			counter++;

			arr[k] = Larray[i];
			i = i + 1;
		}
		else {
			arr[k] = Rarray[j];

			j = j + 1;
		}

		k++;

	}

	while (i < n1) {

		arr[k] = Larray[i];

		i++;
		k++;

	}

	while (j < n2) {
		arr[k] = Rarray[j];
		j++;
		k++;
	}

	return counter;

}

// n is the length of the array
int HeapSort(int arr[], int n)
{
	int counter = 0;

	//  adds the counter of Build_Max_Heap(it also builds the heap)
	counter = counter + BUILD_MAX_HEAP(arr, n);

	// this for loop shows decrement because it extracts an element from the heap
	for (int i = n - 1; i >= 0; i--)
	{
		// 1 is the root of the heap
		swap(arr[0], arr[i]);

		// adds to the counter the comparisons made in  MAX_HEAPIFY
		counter = counter + MAX_HEAPIFY(arr, i, 0);

	}
	// returns the number of comparisons in Heapsort 
	return counter;

}


int BUILD_MAX_HEAP(int arr[], int n)
{
	// n = length[A] on pseudo

	// loop is decrementing

	int counter = 0;
	for (int i = (n / 2) - 1; i >= 0; i--)


		counter = counter + MAX_HEAPIFY(arr, n, i);

	return counter;
}


//To heapify a subtree rooted with node i which is
// an index in arr[]. n is size of heap
int MAX_HEAPIFY(int arr[], int n, int i)
{
	// counter for comparisons made in the MAX_HEAPIFY 
	int counter = 0;

	int left = 2 * i + 1; // left child
	int right = 2 * i + 2; // right child
	int largest = i; // initialize largest root 


					 // If left child is larger than root
	if (left < n && arr[left] > arr[largest])
	{
		counter++;
		largest = left;
	}


	// If right child is larger than largest 
	if (right < n && arr[right] > arr[largest])
	{
		counter++;
		largest = right;
	}

	// If largest is not root
	if (largest != i)
	{
		swap(arr[i], arr[largest]);

		// Recursively heapify the affected sub-tree
		counter = counter + MAX_HEAPIFY(arr, n, largest);
	}

	return counter;
}

// comparison count DONE! SORTS ARRAY TOO!
// To display the comparisons, u cout count in main
int QuickSort(int arr[], int p, int r)
{
	int counter = 0;
	int q;
	if (p < r)
	{
		// the counter is already in memory
		q = PARTITION(arr, p, r, &counter);

		QuickSort(arr, p, q - 1);
		QuickSort(arr, q + 1, r);

	}
	return counter;

}
// partition counts for quicksort
int PARTITION(int arr[], int p, int r, int *counter)
{
	// a pointer is used to store counter in the function, it is then returned in QuickSort
	int x = arr[r];
	int i = p - 1;

	for (int j = p; j <= (r - 1); j++)
	{
		(*counter) = (*counter) + 1;
		if (arr[j] <= x)
		{
			
			i = i + 1;
			// do exchange

			swap(arr[i], arr[j]);
		}


	}

	// do exchange line 7 on pseudocode

	swap(arr[i + 1], arr[r]);

	return (i + 1);
}


// Function to reverse arr[] from start to end, 
// this function only works if the array is sorted
// start is the beggining of the array, end is the las index
void RevereseArray(int arr[], int start, int end)
{
	while (start < end)
	{
		int temp = arr[start];
		arr[start] = arr[end];
		arr[end] = temp;
		start++;
		end--;
	}
}