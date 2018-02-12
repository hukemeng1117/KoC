#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


typedef struct _TreeNode
{
	int data;
	struct _TreeNode* leftChild;
	struct _TreeNode* rightChild;
}treeNode,*pTreeNode;

void pushTree(pTreeNode* parent,int flag,int data){
	pTreeNode tempNode = (pTreeNode)malloc(sizeof(treeNode));
	if(tempNode == NULL){
		return;
	}
	if((*parent) == NULL){
		*parent = (pTreeNode)malloc(sizeof(treeNode));
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
		*parent = tempNode;
	}
}



void TreeStruct(int* preorder,int* midorder,int length,int flag1,pTreeNode* parent){
	if(preorder == NULL || midorder == NULL || length <= 0){
		return;
	}
	int data = preorder[0];
	int flag = 0;

	pushTree(parent,flag1,data);

	for(int i = 0;i < length;i++){
		if(data == midorder[i]){
			flag = i;
		}
	}

	int* leftPreorder = (int*)malloc(flag*sizeof(int));
	int* rightPreorder = (int*)malloc((length-flag-1)*sizeof(int));
	for(int j = 1;j < flag+1;j++){
		leftPreorder[j-1] = preorder[j];
	}
	for(int j = flag+1;j <length;j++){
		rightPreorder[j-flag-1] = preorder[j];
	}

	int* leftMidorder = (int*)malloc(flag*sizeof(int));
	int* rightMidorder = (int*)malloc((length-flag-1)*sizeof(int));
	for(int j = 0;j < flag;j++){
		leftMidorder[j] = midorder[j];                   
	}
	for(int j = flag+1;j <length;j++){
		rightMidorder[j-flag-1] = midorder[j];
	}
	
	//pTreeNode parent1 = (pTreeNode)malloc(sizeof(treeNode));
	TreeStruct(leftPreorder,leftMidorder,flag,0,parent);

	//pTreeNode parent2 = (pTreeNode)malloc(sizeof(treeNode));
	TreeStruct(rightPreorder,rightMidorder,length-flag-1,1,parent);

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
	
	int preorder[8] = {1,2,4,7,3,5,6,8};
	int midorder[8] = {4,7,2,1,5,3,8,6};

	pTreeNode parent = NULL;
	// pushTree(&parent,1,1);
	// pushTree(&parent,0,2);
	// pushTree(&parent,1,3);

	TreeStruct(preorder,midorder,8,0,&parent);
	printTree(parent); 

	return 0;
}