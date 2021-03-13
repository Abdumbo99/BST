#ifndef __ANALYSIS__H
#define __ANALYSIS__H
#include "PbBST.h"
/**
* Title : Binary Search Trees
* Author : ABDULRAZAK DAHERKHATIB
* ID: 21801340
* Section : 001
* Assignment : 2
* Description :header file for the analysis file we only provide the headers of necessary functions here
*/
void heightAnalysis();	//the required function 
void createfillArray(int* arr);	// here we create and fill the arrays with random ints
void fillTree(int* arr, PbBST& testTree);	// we fill the tree with the values in array and print at each 1500 elements
void emptyTree(int* arr, PbBST& testTree);	// we delete elements from the tree with the values in array and print at each 1500 elements

#endif
