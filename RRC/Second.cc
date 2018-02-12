#include <stdio.h>
#include <stdlib.h>

typedef struct _treeNode {
    int data;
    struct _treeNode *left;
    struct _treeNode *right;
}*treeNode;

treeNode initTreeNode(int data) {
    treeNode t = (treeNode)malloc(sizeof(treeNode));
    if(t == NULL) {
        return NULL;
    }
    
    t->data = data;
    t->left = NULL;
    t->right = NULL;
    
    return t;
}

void preTransferTree(treeNode parent) {
    printf("%d  ",parent->data);
    if(parent->left != NULL) {
        preTransferTree(parent->left);
    }
    if(parent->right != NULL) {
        preTransferTree(parent->right);
    }
}

void midTransferTree(treeNode parent) {
    if(parent->left != NULL) {
        midTransferTree(parent->left);
    }
    printf("%d  ",parent->data);
    if(parent->right != NULL) {
        midTransferTree(parent->right);
    }

}

void backTransferTree(treeNode parent) {
    if(parent->left != NULL) {
        backTransferTree(parent->left);
    }
    if(parent->right != NULL) {
        backTransferTree(parent->right);
    }
    printf("%d  ",parent->data);
}

void lineTransferTree  (treeNode parent){
    treeNode a[100] = {0};
    a[0] = parent;
    int i = 0;
    int k = 1;
    while(parent){
        if(parent->left != NULL){
            i++;
            a[i] = parent->left;
        }
        if(parent->right != NULL){
            i++;
            a[i] = parent->right;
        }
        parent = a[k++];
    }
    for(int j=0;j<=i;j++) {
        printf("%d  ",a[j]->data);
    }
}

int getNumLeaf(treeNode parent) {
	static int num = 0;
    if(parent -> left != NULL) {
        getNumLeaf(parent-> left);
    }
    if(parent -> right != NULL) {
        getNumLeaf(parent->right);
    }
    if(parent->left == NULL && parent->right == NULL) {
    	num += 1;
        return num;
    } else {
        return num;
    }
}

int getTreeDeepth(treeNode parent){
    int deepth = 1;
    int max = 1;
    if(parent -> left != NULL) {
        deepth = getTreeDeepth(parent-> left) + 1;
        if(deepth >= max) {
            max = deepth;
        }
    }
    if(parent -> right != NULL) {
        deepth = getTreeDeepth(parent-> right) + 1;
        if(deepth >= max) {
            max = deepth;
        }
    }
    
    return max;
}

int main() {
    treeNode parent = initTreeNode(12);
    treeNode node1 = initTreeNode(13);
    treeNode node2 = initTreeNode(14);
    treeNode node3 = initTreeNode(15);
    treeNode node4 = initTreeNode(16);
    treeNode node5 = initTreeNode(17);
    
    parent->left = node1;
    parent->right = node3;
    node1->left = node2;
    node2->right = node4;
    node3->left = node5;
    
    preTransferTree(parent);
    printf("\n");
    midTransferTree(parent);
    printf("\n");
    backTransferTree(parent);
    printf("\n");
    lineTransferTree(parent);
    
    printf("\n\n%d\n",getNumLeaf(parent, 0));
    printf("\n\n%d\n",getTreeDeepth(parent));

}
