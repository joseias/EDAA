/********************************************************************************
* 																				*
* Recursive definition of the ADT Binary Tree									*
* 																				*
********************************************************************************/

#include "ADT_BinaryTreeRecursive.h"

void testTreeTraversals(){
	BinaryTree* n1 = createTree(1,NULL,NULL);
	BinaryTree* n6 = createTree(6,NULL,NULL);
	BinaryTree* n10 = createTree(10,NULL,NULL);
	BinaryTree* n20 = createTree(20,NULL,NULL);
	BinaryTree* n32 = createTree(32,NULL,NULL);

	BinaryTree* n4 = createTree(4,n1,n6);
	BinaryTree* n12 = createTree(12,n10,NULL);
	BinaryTree* n8 = createTree(8,n4,n12);
	BinaryTree* n25 = createTree(25,n20,n32);

	BinaryTree* n17 = createTree(17,n8,n25);

	printf("Tree height -> %d \n", height(n17));


	ll_List* pre = ll_create();
	ll_List* in = ll_create();
	ll_List* pos = ll_create();

	preOrder(n17, pre);
	inOrder(n17, in);
	posOrder(n17,pos);

	int i;
	printf("preOrder -> ");
	for(i=0;i<ll_size(pre);i++){
		printf("%d ", ll_get(pre,i));
	}
	printf("\n");

	printf("inOrder -> ");
	for(i=0;i<ll_size(in);i++){
		printf("%d ", ll_get(in,i));
	}
	printf("\n");

	printf("posOrder -> ");
	for(i=0;i<ll_size(pos);i++){
		printf("%d ", ll_get(pos,i));
	}
	printf("\n");

}

void testTreeInsertion(){

	BinaryTree* t = createTree(NULL, NULL, NULL);
	bstInsert(t,17);
	bstInsert(t,8);
	bstInsert(t,4);
	bstInsert(t,1);
	bstInsert(t,6);
	bstInsert(t,12);
	bstInsert(t,10);
	bstInsert(t,25);
	bstInsert(t,20);
	bstInsert(t,32);

	ll_List* pre = ll_create();
	ll_List* in = ll_create();
	ll_List* pos = ll_create();

	preOrder(t, pre);
	inOrder(t, in);
	posOrder(t,pos);

	int i;
	printf("preOrder -> ");
	for(i=0;i<ll_size(pre);i++){
		printf("%d ", ll_get(pre,i));
	}
	printf("\n");

	printf("inOrder -> ");
	for(i=0;i<ll_size(in);i++){
		printf("%d ", ll_get(in,i));
	}
	printf("\n");

	printf("posOrder -> ");
	for(i=0;i<ll_size(pos);i++){
		printf("%d ", ll_get(pos,i));
	}
	printf("\n");

	BinaryTree* min = bstFindMin(t->left);
	BinaryTree* max = bstFindMax(t->left);

	if(min != NULL){
		printf("Min -> %d\n", min->element);
	}

	if(max != NULL){
		printf("Max -> %d\n", max->element);
	}
	printf("\n");

	bstDelete(t,17);

	pre = ll_create();
	in = ll_create();
	pos = ll_create();

	preOrder(t, pre);
	inOrder(t, in);
	posOrder(t,pos);

	printf("preOrder -> ");
	for(i=0;i<ll_size(pre);i++){
		printf("%d ", ll_get(pre,i));
	}
	printf("\n");

	printf("inOrder -> ");
	for(i=0;i<ll_size(in);i++){
		printf("%d ", ll_get(in,i));
	}
	printf("\n");

	printf("posOrder -> ");
	for(i=0;i<ll_size(pos);i++){
		printf("%d ", ll_get(pos,i));
	}
	printf("\n");


}

BinaryTree* createTree(int element, BinaryTree* left, BinaryTree* right){
	BinaryTree* t=(BinaryTree*) malloc(sizeof(BinaryTree));
	t->element = element;
	t->left=left;
	t->right=right;
	int lsize = left == NULL? 0 : left ->size;
	int rsize = right == NULL? 0 : right ->size;
	t->size= lsize + rsize;
	
	return t;
}

void bstInsert(BinaryTree* t, int element){
	if(t != NULL){
		if(t->size>0){
			if(t->element != element){
				/*Insert to the left*/
				if( element < t->element){
					if(t->left !=NULL){
						bstInsert(t->left, element);
					}
					else{
						t->left = createTree(element, NULL, NULL);
					}
				}
				/*Insert to the right*/
				else{
					if(t->right !=NULL){
						bstInsert(t->right, element);
					}
					else{
						t->right = createTree(element, NULL, NULL);
					}
				}
			}
		}
		else{
			t->element = element;
		}

		t->size++;
	}
	else{
		fprintf(stderr, "Inserting in a NULL tree...");
		exit(EXIT_FAILURE);
	}
}

void bstDelete(BinaryTree* t, int element){
	bool empty = false;
	if(t != NULL){
		if(element < t->element && t->left != NULL){
			/* element < t-> element and t->left == NULL
			 * implies the element is not in the tree*/
			bstDelete(t->left, element);
		}

		if(element > t->element && t->right != NULL){
			/* element > t-> element and t->right == NULL
			 * implies the element is not in the tree*/
			bstDelete(t->right,element);
		}


		if(t->element == element){
			/* Replace t->element by its lower right child
			 * and delete the value from the right sub-tree*/
			if(t->right != NULL){
				BinaryTree* suc = bstFindMin(t->right);
				t->element = suc->element;
				bstDelete(t->right, suc->element);
			}
			else{
				/*No right child, test if there is a left child*/
				if(t->left != NULL){
					BinaryTree* pred = bstFindMax(t->left);
					t->element = pred->element;
					bstDelete(t->left, pred->element);
				}
				else{
					/*Both, left and right are NULL*/
					t->element = 0;
					t->size = 0;
					empty = true;
				}
			}
		}


		if(t->right!=NULL && t->right->size == 0){
			free(t->right);
			t->right = NULL;
		}

		if(t->left != NULL && t->left->size == 0){
			free(t->left);
			t->left = NULL;
		}

		t->size = (t->left != NULL? size_tree(t->left):0) + (t->right != NULL? size_tree(t->right):0) + (empty? 0:1);
	}
	else{
		fprintf(stderr, "Deleting in a NULL tree...");
		exit(EXIT_FAILURE);
	}
}

BinaryTree* bstSearch(BinaryTree* t, int element){

	if((t==NULL) || (element == t->element) ){
		return t;
	}
	else{
		if(element < t->element){
			return bstSearch(t->left,element);
		}
		else{
			return bstSearch(t->right,element);
		}
	}
}


BinaryTree* bstFindMin(BinaryTree* t){
	if(t != NULL){
		if(t->left != NULL){
			return bstFindMin(t->left);
		}
		else{
			return t;
		}
	}
	else{
		return NULL;
	}
}

BinaryTree* bstFindMax(BinaryTree* t){
	if(t != NULL){
		if(t->right != NULL){
			return bstFindMax(t->right);
		}
		else{
			return t;
		}
	}
	else{
		return NULL;
	}
}


void preOrder(BinaryTree* t, ll_List* elements){
	ll_add(elements, t->element);
	if(t->left != NULL){
		preOrder(t->left,elements);
	}
	if(t->right != NULL){
		preOrder(t->right, elements);
	}
}
void inOrder(BinaryTree* t, ll_List* elements){
	if(t->left != NULL){
		inOrder(t->left,elements);
	}

	ll_add(elements, t->element);

	if(t->right != NULL){
		inOrder(t->right,elements);
	}
}

void posOrder(BinaryTree* t, ll_List* elements){

	if(t->left != NULL){
		posOrder(t->left,elements);
	}
	if(t->right != NULL){
		posOrder(t->right, elements);
	}
	ll_add(elements, t->element);
}

int height(BinaryTree* t){
	if(t->left == NULL && t-> right == NULL){
		return 0;
	}
	else{
		int leftH=0;
		if(t->left != NULL){
			leftH=height(t->left);
		}

		int rightH=0;
		if(t->right != NULL){
			rightH=height(t->right);
		}

		return 1+ (leftH>rightH? leftH:rightH);
	}
}

int size_tree(BinaryTree* t){
	return t->size;
}
