#include "analysis.h"
#include <algorithm>

/**
* Title : Binary Search Trees
* Author : ABDULRAZAK DAHERKHATIB
* ID: 21801340
* Section : 001
* Assignment : 2
* Description :cpp file for the analysis file we only provide the headers of necessary functions here
*/


void createfillArray(int* arr) {
	for (int i = 0; i < 15000; i++) //fill with random
		arr[i] = rand();
}
void fillTree(int* arr, PbBST& testTree) {

	cout << "Part e - Height analysis of Binary Search Tree - part 1\n ---------------------------------------------\n"<<"Tree size:\t\t Tree Height: \n  ---------------------------------------------"<< endl;
		
	for (int i = 0; i < 15000; i++) {

		testTree.insertKey(arr[i]);
		if (i % 1500 == 1499 && i != 0  ) // 1500s elements, print
			cout << i +1 << "\t\t\t" << testTree.getHeight() << endl;
	}
}

void emptyTree(int* arr, PbBST& testTree) {

	cout << "Part e - Height analysis of Binary Search Tree - part 2\n ---------------------------------------------\n"<<
		"Tree size:\t\t Tree Height: \n  ---------------------------------------------" << endl;

	for (int i = 0; i < 15000; i++) {

		testTree.deleteKey(arr[i]);
		if (i % 1500 == 0  )  // 1500s elements, print
			cout << 15000 - i << "\t\t\t" << testTree.getHeight() << endl;
	}
}

void heightAnalysis() {
	int* arr = new int [15000];	// create array on heap
	PbBST testTree;	// create tree on stack 
	createfillArray(arr);	// 
	fillTree(arr, testTree);
	random_shuffle(&arr[0], &arr[15000]); // shuffle
	emptyTree(arr, testTree);
	delete []arr;
}
