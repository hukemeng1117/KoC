#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct _listNode
{
	int data;
	struct _listNode* next;
}Node,*pNode;

void pushNode(pNode* pHead,int data){
	pNode tempNode = (pNode)malloc(sizeof(Node));
	

	tempNode ->data = data;
	tempNode ->next = NULL;


	if(*pHead == NULL){
		*pHead = tempNode;
	}else{
		pNode tempNode2 = *pHead;
		while(tempNode2 ->next != NULL){
			tempNode2 = tempNode2 ->next;
		}
		tempNode2 -> next = tempNode;
	}
}

void printLink(pNode pHead){
	if(pHead == NULL){
		return;
	}
	
	pNode tempNode = pHead;
	while(tempNode -> next != NULL){
		printf("%5d",tempNode -> data);
		tempNode = tempNode ->next;
	}	
	printf("%5d",tempNode -> data);
}

pNode mergeLink(pNode pHead1,pNode pHead2){
	pNode pHead = NULL;
	pNode tempNode1 = pHead1;
	pNode tempNode2 = pHead2;
	while((tempNode1 != NULL) && (tempNode2 != NULL)){
		if((tempNode1 -> data) <= (tempNode2 -> data)){
			pushNode(&pHead,(tempNode1 -> data));
			//printf("%d  %d\n",tempNode1 -> data,tempNode2 -> data);
			//printf("%d\n",(*pHead) -> data);
			tempNode1 = tempNode1 -> next;
		}else{
			pushNode(&pHead,tempNode2 -> data);
			tempNode2 = tempNode2 -> next;
		}
	}
	while(tempNode1 != NULL){
		pushNode(&pHead,tempNode1 -> data);
		tempNode1 = tempNode1 -> next;
	}
	while(tempNode2 != NULL){
		pushNode(&pHead,tempNode2 -> data);
		tempNode2 = tempNode2 -> next;
	}
	return pHead;

}


int main(int argc, char const *argv[])
{
	pNode pHead1 = NULL;
	for(int i = 0;i < 100;i++){
		pushNode(&pHead1,i);
	}	
	printLink(pHead1);
	printf("%s\n","");

	pNode pHead2 = NULL;
	for(int i = 0;i < 100;i++){
		pushNode(&pHead2,2*i);
	}	
	printLink(pHead2);
	printf("%s\n","");


	
	printLink(mergeLink(pHead1,pHead2));


	return 0;
	
	
}