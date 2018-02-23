#include <stdio.h>
#include <stdlib.h>

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


void deleteNode(pNode* pHead,pNode toBeDeleted){
	if(pHead == NULL || toBeDeleted == NULL){
		return;
	}
	if(toBeDeleted -> next != NULL){
		pNode tempNode = toBeDeleted -> next;
		toBeDeleted -> data = tempNode -> data;
		toBeDeleted -> next = tempNode -> next;
		free(tempNode);
	}else if((*pHead) == toBeDeleted){
		free(toBeDeleted);
		*pHead = NULL;		
	}else{
		pNode tempNode = *pHead;
		while(tempNode -> next ->next != NULL){
			tempNode = tempNode -> next;
		}
		pNode tempNode2 = tempNode -> next;
		tempNode -> next = NULL;
		free(tempNode2);


	}




}

int main(int argc, char const *argv[])
{
	pNode pHead = NULL;
	for(int i = 0;i < 100;i++){
		pushNode(&pHead,i);
	}	
	printLink(pHead);
	printf("%s\n","");


	pNode toBeDeleted = pHead;
	deleteNode(&pHead,toBeDeleted);
	printLink(pHead);
	printf("%s\n","");
		

	pNode tempNode = pHead;
	while(tempNode -> next != NULL){
		tempNode = tempNode ->next;
	}	
	deleteNode(&pHead,tempNode);
	printLink(pHead);

	return 0;
	
	
}