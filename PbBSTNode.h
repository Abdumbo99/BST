#ifndef __PBBSTNODE__H
#define __PBBSTNODE__H
using namespace std;
#include <cmath>
#include  <iostream>
/**
* Title : Binary Search Trees
* Author : ABDULRAZAK DAHERKHATIB
* ID: 21801340
* Section : 001
* Assignment : 2
* Description :Header file for the Node of binary tree
*/

class PbBSTNode { // node in the tree
private:
	PbBSTNode() {}
	PbBSTNode(const int& item, PbBSTNode* left = NULL, PbBSTNode* right = NULL) :item(item), leftChild(left), rightChild(right) {}
	int item;  // data porton
	PbBSTNode* leftChild;  // pointer to left child
	PbBSTNode* rightChild;  // pointer to right child
	friend class PbBST;		// so it can access private members
};

#endif
