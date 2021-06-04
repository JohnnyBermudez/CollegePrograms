#include<iostream>
#include "BSTs.h"
/*
Juan Bermudez
CMPE 3333
#20158030
Project 5
*/
using namespace std;

int main()
{
	// 
	BinarySearchTree tree;

	// tree T used in SubBST function
	BinarySearchTree T;

	// binary search tree for enhanced search
	BinarySearchTree En;

	// sizes determined for filling in an array in BST
	const int size1 = 7;
	const int size2 = 3;
	const int size3 = 6;

	// max inputs
	int keys3[size3];


	// value searched for on enhanced search
	int k;


	// holds a value from the tree
	treeNode *temp;

	// holds value of choice entered by user input
	int choice, ch;

	//int* keys;
	//keys = new int[size1];
	int keys[size1];

	// used to create SubBST 1
	int keys1[size2];


	// menu driven program to test BST functions
	while (true)
	{

		cout << endl;
		cout << " BST functions";
		cout << endl << endl;

		cout << " 1. Insert nodes" << endl;
		cout << " 2. Inorder Traversal" << endl;
		cout << " 3. Postorder Traversal" << endl;
		cout << " 4. Preorder Traversal" << endl;
		cout << " 5. Search Maximum" << endl;
		cout << " 6. Search Minimum" << endl;
		cout << " 7. Search" << endl;
		cout << " 8. Predecessor" << endl;
		cout << " 9. Sucessor" << endl;
		cout << " 10. Delete" << endl;
		cout << " 11. Sub-BST" << endl;
		cout << " 12. Enhanced Search" << endl;
		cout << " 13. Exit" << endl << endl;

		cout << " Enter a choice: " << endl;
		cin >> choice;

		switch (choice)
		{

		case 1: cout << " Insert values into BST" << endl;

			for (int i = 0; i < size1; i++)
			{
				cin >> keys[i];
			}

			// initialize tree's root
			tree.root = nullptr;

			// insert bst test
			// insert the keys into the tree
			for (int key : keys)
				tree.root = tree.Insert(tree.root, key);

			break;

		case 2: cout << endl << endl;

			cout << " Inorder display" << endl;
			// test Inorder	
			tree.Inorder(tree.root);

			break;

		case 3:
			cout << endl << endl;
			// postorder test
			cout << " Postorder display" << endl;

			tree.Postorder(tree.root);

			break;

		case 4:
			cout << endl << endl;
			// preorder test
			cout << " Preorder display" << endl;

			tree.Preorder(tree.root);
			break;

		case 5:
			cout << endl << endl;

			cout << " Search Maximum" << endl;

			// test SearchMax

			temp = tree.SearchMax(tree.root);

			cout << " Maximum element is " << temp->data;


			break;

		case 6:
			cout << endl << endl;

			cout << " Search Minimum" << endl;

			// test SearchMin
			temp = tree.SearchMin(tree.root);
			cout << endl;

			cout << " Minimum is " << temp->data;
			cout << endl;

			break;

		case 7:
			cout << endl << endl;
			
			// Test Search bst function
			cout << " Enter element to Search in BST" << endl;

			cin >> ch;
			cout << endl;

			// test Search function
			temp = tree.Search(tree.root, ch);
			if (temp == NULL)
			{
				cout << "The element was not found";
			}
			else
			{
				cout << "The Element " << temp->data << " was Found\n";
			}
			break;

		case 8:
			cout << endl << endl;

			cout << "Predecessors of BST" << endl;

			// for loop from the inputted nodes on choice 1, inserted nodes
			for (int key : keys)
			{
				treeNode* prec = nullptr;
				tree.Predecessor(tree.root, prec, key);

				if (prec != nullptr)
					cout << "The Predecessor of node " << key << " is " << prec->data;
				else
					cout << "The Predecessor doesn't exists for node " << key;

				cout << '\n';
			}

			break;

		case 9:
			cout << endl << endl;

			cout << " Successors of BST" << endl;

			// find in-order Successor for each key
			for (int key : keys)
			{
				treeNode* prec = nullptr;
				tree.Successor(tree.root, prec, key);

				if (prec != nullptr)
					cout << "Successor of node " << key << " is " << prec->data;
				else
					// node does not have a successor if it is the top node, or the last child
					cout << "The Successor doesn't exists for node " << key;

				cout << '\n';
			}


			break;

		case 10:
			cout << endl << endl;

			cout << " Enter a node to Delete" << endl;
			cin >> ch;
			tree.Delete(tree.root, ch);
			cout << endl << " After deletion, the BST is: " << endl;
			tree.Inorder(tree.root);

			break;

		case 11:
			cout << endl << endl;

			cout << "Test if a BST is a Sub-BST of another BST " << endl;

			// Create BST T

			cout << " Insert values into T" << endl;

			for (int i = 0; i < size2; i++)

			{

				cin >> keys1[i];

			}

			// initialize tree's root

			T.root = nullptr;

			// insert pst test

			// insert the keys into the tree

			for (int key : keys1)

				T.root = tree.Insert(T.root, key);

		

	// test the inputs with the current tree

			if (tree.isSubtree(tree.root, T.root))

				printf("T is a subtree of Tree ");

			else

				printf("T is not a subtree of Tree ");



			break;

		case 12:
			cout << endl << endl;



			cout << "Enhanced Search of a BST " << endl;

			// Create BST En
			cout << " Insert values into Enhanced Tree" << endl;

			for (int i = 0; i < size3; i++)
			{

				cin >> keys3[i];

			}

			// initialize tree's root

			En.root = nullptr;

			// insert bst test

			// insert the keys into the tree

			for (int key : keys3)

				En.root = En.Insert(En.root, key);


			cout << " Enter element to Search in the BST, and return 3 values close to it: " << endl;

			cin >> k;
			cout << endl;

			En.EnhancedSearch(En.root, k);
			// initialize enhanced search procedure, search for 3 key values close to k




			break;

		case 13:
			cout << endl << endl;

			cout << "Exit" << endl;
			exit(0);

			break;

		default:
			cout << "Enter a valid choice:";
			break;
		}
	}
	/*tree test 1 with tree below
	18
	/ \
	/	  \
	12	   21
	/ \	   / \
	/   \  /   \
	9	   14 17   25
	*/

	// keys to be inserted into the tree
	//int keys[] = { 18, 12, 21, 9, 14, 17, 25 };



	//tree.root = tree.Insert(tree.root, 9);

	//tree.root = tree.Insert(tree.root, 2);

	//tree.root = tree.Insert(tree.root, 10);

	//tree.root = tree.Insert(tree.root, 5);

	//cout << "Printing preorder" << endl;

	//tree.Preorder(tree.root);





	//cout << "\nDeleting 2" << endl;

	//tree.Delet(tree.root, 2);

	//	cout << "Printing preorder" << endl;

	//tree.Preorder(tree.root);

	//cout << "\nPrinting inorder" << endl;

	//tree.Inorder(tree.root);

	//cout << "\nPrinting postorder" << endl;

	//tree.Postorder(tree.root);

	return 0;

}
