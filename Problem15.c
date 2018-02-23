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

int findKThToTail(pNode pHead,int k){
	if(pHead == NULL || k <= 0){
		return -1;
	}
	int index = 1;
	pNode tempNode = pHead;
	while(index < k){
		if(tempNode -> next == NULL){
			return -1;
		}
		tempNode = tempNode -> next;
		index++;
	}
	pNode tempNode2 = pHead;
	while((tempNode -> next != NULL) && (tempNode2 -> next != NULL)){
		tempNode = tempNode -> next;
		tempNode2 = tempNode2 -> next;
		index++;
	}

	if(index < k){
		return -1;
	}
	return tempNode2 -> data;
}


int main(int argc, char const *argv[])
{
	pNode pHead = NULL;
	for(int i = 0;i < 100;i++){
		pushNode(&pHead,i);
	}	
	printLink(pHead);
	printf("%s\n","");

	printf("%5d\n",findKThToTail(pHead,1));

	return 0;
	
	
}