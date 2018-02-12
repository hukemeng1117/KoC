#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct _TreeNode
{
	int data;
	struct _TreeNode* leftChild;
	struct _TreeNode* rightChild;
}treeNode,*pTreeNode;

// 生成树上的一个节点
pTreeNode createTreeNode(int data) {
	pTreeNode parent;
	assert((parent = (pTreeNode)malloc(sizeof(treeNode))) != NULL);
	parent->data = data;
	parent->leftChild = NULL;
	parent->rightChild = NULL;
	return parent;
}

// 生成树，返回树的根节点
void createTree(int *preorder,int *midorder,int length,pTreeNode parent) {
	if(length <= 0)
		return;
	assert(preorder != NULL && midorder != NULL && parent != NULL);

	int preIndex = 0;
	int midIndex = 0;
	
	while(preorder[preIndex] != parent->data && preIndex < length) 
		preIndex ++;
	while(midorder[midIndex] != parent->data && midIndex < length)
		midIndex ++;

	assert(midIndex != length && preIndex != length);
	
	if(preIndex != midIndex) {
		parent->leftChild = createTreeNode(preorder[preIndex+1]);
		createTree(preorder+1,midorder,midIndex,parent->leftChild);
	}

	if(midIndex+1 < length) {
		parent->rightChild = createTreeNode(preorder[midIndex+1]);
		createTree(preorder+midIndex+1,midorder+midIndex+1,length-midIndex-1,parent->rightChild);
	}
}

void printTree(pTreeNode node){
	assert(node != NULL);

	if(node->leftChild != NULL)
		printTree(node->leftChild);
	if(node->rightChild != NULL)
		printTree(node->rightChild);

	printf("%d ", node->data);
}

int main(int argc, char const *argv[])
 {
 	int preorder[8] = {1,2,4,7,3,5,6,8};
	int midorder[8] = {4,7,2,1,5,3,8,6};

 	pTreeNode parent = createTreeNode(preorder[0]);
 	createTree(preorder,midorder,8,parent);

 	printTree(parent);

 	return 0;
 } 