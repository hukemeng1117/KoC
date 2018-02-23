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

void reverseLink(pNode* pHead){
	if(*pHead == NULL || (*pHead) -> next == NULL){
		return;
	}
	pNode tempNode = *pHead;
	pNode tempNode2 = (*pHead) -> next;
	pNode tempNode3 = (*pHead) -> next -> next;

	(*pHead) -> next = NULL;
	while(tempNode2 != NULL){
		tempNode2 -> next = tempNode;
		tempNode = tempNode2;
		tempNode2 = tempNode3;
		if(tempNode3 != NULL){			
			tempNode3 = tempNode3 -> next;
		}

	}
	*pHead = tempNode;	
}


int main(int argc, char const *argv[])
{
	pNode pHead = NULL;
	for(int i = 0;i < 100;i++){
		pushNode(&pHead,i);
	}	
	printLink(pHead);
	printf("%s\n","");


	reverseLink(&pHead);
	printLink(pHead);


	return 0;
	
	
}