#ifndef __PBBST__H
#define __PBBST__H
#include "PbBSTNode.h"
using namespace std;
/**
* Title : Binary Search Trees
* Author : ABDULRAZAK DAHERKHATIB
* ID: 21801340
* Section : 001
* Assignment : 2
* Description :Header file for the binary tree 
*/

class PbBST { // node in the tree
private:
	PbBSTNode* root;

public: // accessible functions by user
	PbBST();
	void insertKey(int key);
	void deleteKey(int key);
	int getHeight();
	int getNodeCount();
	int findNodesRequired();
	void mirrorTree();
	void preorderTraversal();
	double medianOfBST();
	
protected: // protected since they are helper functions that the user do not need to access
	void insert(PbBSTNode*& ptr, int key);
	void deleteItem(PbBSTNode*& ptr, int key);
	void deleteNode(PbBSTNode*& ptr);
	void processLeftmost(PbBSTNode*& ptr, int& key);
	int getHeightHelper(PbBSTNode* ptr);
	void getNodeCountHelper(PbBSTNode* ptr, int& count);
	void mirrorTreeHelper(PbBSTNode* ptr);
	void preorderTraversalHelper(PbBSTNode* ptr);
	int findNthInorder(PbBSTNode*& ptr, int ind, int& count, int nodesNum);
};

#endif