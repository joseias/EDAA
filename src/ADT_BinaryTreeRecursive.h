/********************************************************************************
* 																				*
* Recursive definition of the ADT Binary Tree									*
* 																				*
********************************************************************************/

#ifndef BINARYTREERECURSIVE_H_
#define BINARYTREERECURSIVE_H_

#include "ADT_List_DoubleLinked.h"

typedef struct binaryTree{
	int element;
	int size;
	struct binaryTree* right;
	struct binaryTree* left;
} BinaryTree;


void testTreeInsertion();
void testTreeTraversals();
BinaryTree* createTree();
void bstInsert(BinaryTree* t, int element);
void bstDelete(BinaryTree* t, int element);
BinaryTree* bstSearch(BinaryTree* t, int element);
BinaryTree* bstFindMax(BinaryTree* t);
BinaryTree* bstFindMin(BinaryTree* t);

BinaryTree* bstSuccessor(BinaryTree* t, int element);
BinaryTree* bstPredecessor(BinaryTree* t, int element);


void inOrder(BinaryTree* t, List* elements);
void preOrder(BinaryTree* t, List* elements);
void posOrder(BinaryTree* t, List* elements);
int height(BinaryTree* t);
int size_tree(BinaryTree* t);
#endif /* BINARYTREERECURSIVE_H_ */
