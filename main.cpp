#include "PbBST.h"
#include "analysis.h" 
#include <cmath>
/**
* Title : Binary Search Trees
* Author : ABDULRAZAK DAHERKHATIB
* ID: 21801340
* Section : 001
* Assignment : 2
* Description :main file for testing and analysis
*/

int main() {
	PbBST* test01 = new PbBST;
	int test[] = {42, 19, 22, 35, 56, 11, 94, 32, 28, 8, 6, 81, 63, 13, 45 };
	int size = 15;
	for (int i = 0; i < size; i++) 
		test01->insertKey(test[i]);

	//test01->preorderTraversal(); testing
	//cout << "Height: " << test01->getHeight() << endl; testing
	cout << "The number of nodes required: " << test01->findNodesRequired() << endl;
	test01->deleteKey(56);
	test01->deleteKey(19);
	//test01->preorderTraversal(); testing
	cout << "Median is: "<< test01->medianOfBST()<< endl;
	test01->mirrorTree();
	test01->preorderTraversal();
	heightAnalysis();
}
