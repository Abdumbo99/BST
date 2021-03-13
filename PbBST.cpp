#include "PbBST.h"
/**
* Title : Binary Search Trees
* Author : ABDULRAZAK DAHERKHATIB
* ID: 21801340
* Section : 001
* Assignment : 2
* Description :Source file for the binary tree
*/


PbBST::PbBST() : root(NULL)
{
} 
void PbBST::insertKey(int key) {
	insert(root, key); // call helper
}
void PbBST::insert(PbBSTNode*& ptr, int key) {
	if (ptr == NULL) // if empty node then create 
		ptr = new PbBSTNode(key, NULL, NULL);
	
	else if (key < ptr->item)
		insert(ptr->leftChild, key); // call on left if smaller than node value
	else
		insert(ptr->rightChild, key); // call on right if smaller than node value

}
void PbBST::deleteKey(int key) {
	deleteItem(root, key); //call helper 
}
void PbBST::deleteItem(PbBSTNode*& ptr, int key) {
	if (ptr == NULL) 
	{
		cout << "No elements in tree" << endl; // empty tree
	}
	else if (key == ptr->item)
		deleteNode(ptr);	//found now delete
	else if (key < ptr->item)
		deleteItem(ptr->leftChild, key); // call on left if smaller than node value
	else
		deleteItem(ptr->rightChild, key);  // call on right if smaller than node value
}

/*
* This is a helper method used for getting the leftmost node, we use this in deletion to find successor
*/
void PbBST::processLeftmost(PbBSTNode*& ptr, int& key) {
	if (ptr->leftChild == NULL) {
		key = ptr->item;
		PbBSTNode* dlPtr = ptr;
		ptr = ptr->rightChild;
		dlPtr->rightChild = NULL;
		delete dlPtr;
	}
	else
		processLeftmost(ptr->leftChild, key); // still did not find the successor
}


void PbBST::deleteNode(PbBSTNode*& ptr) {  // node found; delete now
	PbBSTNode* dlPtr;
	int temp;

	//leaf
	if (ptr->rightChild == NULL && ptr->leftChild == NULL) {
		delete ptr;
		ptr = NULL;
	}

	// one right child
	else if (ptr->leftChild == NULL) {
		dlPtr = ptr;
		ptr = ptr->rightChild;
		dlPtr->rightChild = NULL;
		delete dlPtr;
		dlPtr = NULL;
	}

	//one left child
	else if (ptr->rightChild == NULL) {
		dlPtr = ptr;
		ptr = ptr->leftChild;
		dlPtr->leftChild = NULL;
		delete dlPtr;
		dlPtr = NULL;

	}
	// Two children
	else {
		processLeftmost(ptr->rightChild, temp);
		ptr->item = temp;
	}
}


int PbBST::getHeight() {
	return getHeightHelper(root); //helper
}

int PbBST::getHeightHelper(PbBSTNode* ptr) {
	if (ptr == NULL)
		return 0;
	else
		return (1 + max(getHeightHelper(ptr->leftChild),
			getHeightHelper(ptr->rightChild))); // recurse 
}

int PbBST::getNodeCount() {
	int count = 0;
	getNodeCountHelper(root, count); // helper and pass count 
	return count;
}
void PbBST::getNodeCountHelper(PbBSTNode* ptr, int& count) {
	if (ptr != NULL) {
		count++; // increment and recurse to children

		getNodeCountHelper(ptr->leftChild, count);
		getNodeCountHelper(ptr->rightChild, count);
	}	
}

int PbBST::findNodesRequired() {
	int nodesNum = getNodeCount(); // find # of nodes first
	int height = getHeight(); // find height now 
	int numFull = pow(2.0, height) - 1; // 2^height -  1  = number of elements for full tree
	return numFull - nodesNum;
}
void PbBST::mirrorTree() {
	mirrorTreeHelper(root); // call helper

}
void PbBST::mirrorTreeHelper(PbBSTNode* ptr) {
	if (ptr == NULL)
		return;
	else {
		PbBSTNode* temp = ptr->rightChild; // swap process
		ptr->rightChild = ptr->leftChild;
		ptr->leftChild = temp;
		mirrorTreeHelper(ptr->leftChild); //recurse to children
		mirrorTreeHelper(ptr->rightChild);
	}

}
void PbBST::preorderTraversal() {
	preorderTraversalHelper(root);// recurse to print using helper
}
void PbBST::preorderTraversalHelper(PbBSTNode* ptr) {
	if (ptr != NULL) {
		cout << ptr->item <<endl; //prrint
		preorderTraversalHelper(ptr->leftChild);// now to children
		preorderTraversalHelper(ptr->rightChild);
	}
}

/*
* functiuon used to find the median, we use nth since in even number elements we will get two elements
*/
int PbBST::findNthInorder(PbBSTNode*& ptr, int ind, int& count, int nodesNum) { 

	if (ptr == NULL) {
		return 0; // empty or reached end return 0
	}
	int temp = findNthInorder(ptr->leftChild, ind, count, nodesNum);
	if (temp != 0)
		return temp; // this is a leaf first, then the processed node
	
	if (count == ind) //found element
		return ptr->item;
	count++; //increment 
	return findNthInorder(ptr->rightChild, ind, count, nodesNum); // go to right subtreee
	}


double PbBST::medianOfBST() {
	int count = 0;
	int nodesNum = getNodeCount();
	PbBSTNode* tempPtr = root;
	double median =  findNthInorder(tempPtr, nodesNum/2, count, nodesNum);
	if (nodesNum % 2 == 0) { // in case it is even find the #nodes / 2 + 1 ( for example, 6 / 2 + 1 = 4, now we have 3rd and 4th element )
		count = 0;
		median = (median + findNthInorder(tempPtr, nodesNum / 2 + 1, count, nodesNum)) / 2.0;
	}
	return median;
}