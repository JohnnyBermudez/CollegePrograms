#include<iostream>
/*
Juan Bermudez
CMPE 3333
#20158030
Project 5
*/
using namespace std;

class treeNode

{

public:
	// data to insert in a node, it is known as the key value from the pseudocode 
	int data;

	//a node on the left subtree of a BST, contains only nodes less than key,
	treeNode *left;

	// a node on the right subtree of a BST, contains only nodes greater than key
	treeNode *right;

};

class BinarySearchTree {

public:

	// the top node, usually the parent node
	treeNode * root;

	BinarySearchTree() {

		// root is empty
		root = NULL;

	}

	// function to create a binary tree node, used to test individual bsts
	treeNode* newNode(int key)
	{
		treeNode* node = new treeNode;
		node->data = key;
		node->left = node->right = nullptr;

		return node;

	}

	/*
	// modified from slide 15, successor
	lists all nodes in an inorder treewalk, and finds the maximum key that is next to a given node.
	Searches the left subtree, the maximum key is to the left of the root node in the treewalk*/
	treeNode* Predecessor(treeNode* root, treeNode*& prec, int key)
	{

		// base case for an empty root
		if (root == nullptr)
			return NULL;


		if (root->data == key)
		{
			// searches the left subtree
			if (root->left)

				// the predecessor is found
				prec = SearchMax(root->left);

		}

		// the left tree is element,
		else if (key < root->data)
		{

			Predecessor(root->left, prec, key);

		}

		// if given key is more than the root node, recurse for right subtree

		else
		{
			// update predecessor to parent
			prec = root;
			// searches the right subtree
			Predecessor(root->right, prec, key);

		}

	}

	/*
	Inorder traversal of a BST, searches for the minimum key that is greater than the input node.
	Searches the leftmost element in the right subtree
	*/
	treeNode* Successor(treeNode* root, treeNode*& succ, int key)
	{

		// base case
		if (root == nullptr)

			return NULL;

		// go to the left most element in the right subtree to find a successor
		if (root->data == key)
		{
          // the successor of node x is the node with the smallest key greater than x
		  // search the leftmost node in the right subtree for a successor of a key.
			if (root->right)

				succ = SearchMin(root->right);

		}

		// if the right subtree is empty, and x has y as a successor.
		else if (key < root->data)
		{

			// update successor to parent, and search upwards
			succ = root;
			// search up the tree from node until a node that is the lft child of its parent
			// is encountered
			Successor(root->left, succ, key);

		}

		// if given key is more than the root node, recuse for right subtree

		else
			Successor(root->right, succ, key);

	}

	/* Slide 13, Minimal element in a BST found by following the left subtree from the root
	until NULL is encounterd*/
	treeNode* SearchMin(treeNode *node)
	{
		// search left subtree from the root node until NULL is encountered
		while (node->left != NULL)
		{
			// the minimum node was found
			node = node->left;

		}
		// return the minimum
		return node;

	}

	/* Slide 14, find the maximal element in a BST by following the right
	subtree until NULL is encountered*/
	treeNode* SearchMax(treeNode *node)
	{
		// search right subtree of root Until NULL is encountered
		while (node->right != NULL)
		{
			// max node was found
			node = node->right;

		}
		// return maximum
		return node;

	}

	/* Insert Operation, inserts an element in a tree by searching for it's proper location.
	It searches for the root node, and compares the data to the key value. When the comparison is done,
	the element is inserted in an empty location in the tree.
	*/
	treeNode* Insert(treeNode *node, int data)
	{
		// if the tree has an empty spot then insert a new node
		if (node == NULL)
		{

			treeNode *temp;

			temp = new treeNode;


			temp->data = data;
			// if the nodes are equal then do nothing
			temp->left = temp->right = NULL;

			return temp;

		}
		// if the key is greater than the node, go to the right of the tree
		if (data >(node->data))
		{
			// insert the data to the right
			node->right = Insert(node->right, data);

		}
		// if the key is less than the node, then go to the left of the tree
		else if (data < (node->data))
		{
			// insert the data to the left
			node->left = Insert(node->left, data);

		}

		//return the node that was inserted

		return node;

	}

	// BST for deleting a node from BST, and it's three cases 
	treeNode * Delete(treeNode *node, int data)
	{

		treeNode *temp;
		// if the root is null, then the element was not found
		if (node == NULL)
		{

			cout << "Element Not Found";

		}
		// Case 1: node to be deleted has no children i.e. it is a leaf node, simply remove the leaf
		// search left subtree if key to be deleted is less than the root
		else if (data < node->data)
		{
			// delete if found
			node->left = Delete(node->left, data);

		}
		// if the key to be deleted is greated than the root, search right subtree
		else if (data > node->data)
		{
			// delete key if found
			node->right = Delete(node->right, data);

		}

		else
		{

			// Case 2: node to be deleted has two children
			if (node->right && node->left)

			{


				// find the minimum inorder successor node
				temp = SearchMin(node->right);

				// store the node
				node->data = temp->data;

				// recursively delete the successor. Note that the successor will have at-most one child (right child)
				node->right = Delete(node->right, temp->data);

			}

			else
			{


				temp = node;

				// Case 3: node to be deleted has only one child
				// find the child node if it's on the right or left subtree
				if (node->left == NULL)

					// set the root node to the parent child
					node = node->right;

				else if (node->right == NULL)

					node = node->left;
				// deallocate memory 
				free(temp);

			}

		}

		return node;

	}

	/*  Search Operation on slide 10 of the power point, searches for an element in a tree.
	If data is less than the root node x then search the left side of the BST, other wise if it is greater,
	search the right side.
	*/
	treeNode * Search(treeNode *node, int data)
	{
		// if node is empty, or is equal to data, or if the node is not found 
		if (node == NULL || node->data == data)

		{
			// return the current node, or returns null if null is empty/ not found
			return node;

		}
		// if key is less than the node
		if (data < node->data)
		{

			//Search left side of the root
			return Search(node->left, data);

		}
		else
		{

			// Search right side of the root
			return Search(node->right, data);

		}

	}
	/* Inorder Traversal followed on slide 8.
	Traverses the tree in an in-order manner by visiting the left subtree first, then the root
	and finally the right subtree. The output produces the key values sorted in ascending order
	(increasing)
	*/
	void Inorder(treeNode *node)
	{

		// When root x is not Null, then do the following until all nodes are traversed
		if (node != NULL)
		{
			// recursively traverse left subtree
			Inorder(node->left);

			// print key, the key root is printed between the left and right subtree
			cout << node->data << " ";

			// recursively traverse the right subtree
			Inorder(node->right);

		}

		else {

			// if node is null then there is nothing,

			return;

		}

	}

	/*Modified from slide 8, Preorder traversal
	The root node is visited first, then the left subtree and finally the right subtree
	*/
	void Preorder(treeNode *node) /* preorder traversal */
	{
		// all nodes are traversed
		if (node != NULL)
		{
			// visit root
			// prints the root before the values in either subtree,
			cout << node->data << " ";

			// visit the left subtree
			Preorder(node->left);

			// visit the right subtree
			Preorder(node->right);

		}
		else
		{
			// return nothing if the nodes are empty
			return;

		}

	}

	/*Modified from slide 8, Preorder traversal
	Root node is visited last. First traverse left subtree, and then right.
	*/
	void Postorder(treeNode *node) /* postorder traversal */

	{

		if (node != NULL)

		{
			// traverse left subtree
			Postorder(node->left);

			// traverse right subtree
			Postorder(node->right);

			// post order prints the root after the values in its subtrees.
			cout << node->data << " ";

		}

		else {
			// return nothing if the nodes are empty
			return;

		}

	}

	bool areIdentical(treeNode * root1, treeNode *root2)
	{


		/* base cases, both roots are empty */
		if (root1 == NULL && root2 == NULL)
			return true;

		// if one root is empty, then it is false, cannot be a subtree if it is empty
		if (root1 == NULL || root2 == NULL)
			return false;
		// use pre order to form the comparisons
		Preorder(root1);
		cout << endl;
		Preorder(root2);
		cout << endl;

		/* Check if the data of both roots is same and data of left and right
		subtrees are also same, this is a recursive function, so it will call itself each time in the loop */
		return (root1->data == root2->data   &&
			areIdentical(root1->left, root2->left) &&
			areIdentical(root1->right, root2->right));
	}


	/* This function returns true if S is a subtree of T, otherwise false */
	bool isSubtree(treeNode *T, treeNode *S)
	{
		
		/* base cases */
		if (S == NULL)
			return true;

		if (T == NULL)
			return false;
		// checks the head of both trees, and left and right child. if they are equal then it is true
		//Parent needs to have both childs in order for this to work!, if a child is missing then the program will crash/exit
		if (T->data == S->data && T->left->data == S->left->data && T->right->data == S->right->data)
			return true;
		// checks left subtree of T and checks the nodes from the head of S
		else if (S->data < T->data)
			isSubtree(T->left, S);
		// checks right subtree of T and checks the nodes from the head of S
		else if (S->data > T->data)
			isSubtree(T->right, S);

	}


	void EnhancedSearch(treeNode *T, int k)
	{
		//int min1, min2, min3;
		// go to the head first
		//min1 = T->data - k;
		//min2 = T->left->data - k;
		//min3 = T->right->data - k;


		// When root x is not Null, then do the following until all nodes are traversed
		if (T->data != NULL)
		{
			// recursively traverse left subtree
			Inorder(T->left);

			// print key, the key root is printed between the left and right subtree
			cout << k - T->data << " ";

			// recursively traverse the right subtree
			Inorder(T->right);

		}

		else {

			// if node is null then there is nothing,

			return;

		}


	}

};
