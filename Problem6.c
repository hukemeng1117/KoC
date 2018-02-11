#include <stdio.h>
#include <stdlib.h>


typedef struct _TreeNode
{
	int data;
	struct _TreeNode* leftChild;
	struct _TreeNode* rightChild;
}treeNode,*pTreeNode;

void pushTree(pTreeNode* parent,int flag,int data){
	pTreeNode tempNode = (pTreeNode)malloc (sizeof(treeNode));
	if(tempNode == NULL){
		return;
	}
	if(parent == NULL){
		(*parent) -> data = data;
	}else{
		tempNode ->data = data;
		tempNode ->leftChild = NULL;
		tempNode ->rightChild = NULL;
		if(flag == 0){
			(*parent) -> leftChild = tempNode;
		}else if(flag == 1){
			(*parent) -> rightChild = tempNode;
		}
	}
}



void TreeStruct(int* preorder,int* midorder,int length,int flag1,pTreeNode parent){
	if(preorder == NULL || midorder == NULL || length <= 0){
		return;
	}
	int data = preorder[0];
	int flag = 0;

	for(int i = 0;i < length;i++){
		if(data == midorder[i]){
			flag = i;
		}
	}

	int* leftPreorder;
	int* rightPreorder;
	for(int j = 1;j < flag+1;j++){
		leftPreorder[j-1] = preorder[j];
	}
	for(int j = flag+1;j <length;j++){
		rightPreorder[j-flag-1] = preorder[j];
	}

	int* leftMidorder;
	int* rightMidorder;
	for(int j = 0;j < flag;j++){
		leftMidorder[j] = midorder[j];
	}
	for(int j = flag+1;j <length;j++){
		rightMidorder[j-flag-1] = midorder[j];
	}

	pTreeNode parent1 = (pTreeNode)malloc(sizeof(treeNode));
	parent1 = parent ->leftChild;
	pushTree(*parent1,0,leftPreorder[0]);
	TreeStruct(leftPreorder,leftMidorder,flag,0,parent1);
	pTreeNode parent2 = (pTreeNode)malloc(sizeof(treeNode));
	parent2 = parent ->leftChild;
	pushTree(*parent2,1,rightPreorder[0]);
	TreeStruct(rightPreorder,rightMidorder,length-flag-1,1,parent2);

	
}

void printTree(pTreeNode parent){
	if(parent == NULL){
		return;
	}
	printf("%d\n",parent -> data);
	if(parent -> leftChild != NULL || parent -> rightChild != NULL){
		printf("%s\n","------------");
		printTree(parent ->leftChild);
		printTree(parent ->rightChild);
	}
}

int main(int argc, char const *argv[])
{
	
	// int* preorder = (int*)malloc(8*sizeof(int));
	// preorder = [1,2,4,7,3,5,6,8];
	// int* midorder = (int*)malloc(8*sizeof(int));
	// midorder = [4,7,2,1,5,3,8,6];

	pTreeNode parent;
	pushTree(&parent,1,1);
	pushTree(&parent,0,2);
	//pTreeNode ll = parent -> leftChild;
	pushTree(&parent,1,3);
	printTree(parent);



	return 0;
}