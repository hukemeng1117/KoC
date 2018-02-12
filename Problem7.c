#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct _stacknode
{
	int data;
	struct _stacknode* next;
}stacknode,*pStacknode;

// typedef struct _quenenode
// {
// 	int data;
// 	struct _quenenode* next;
// }quenenode,*pQuenenode;

void pushStack(pStacknode* top,int data){

	pStacknode tempNode = (pStacknode)malloc(sizeof(stacknode));
	tempNode -> data = data;


	if((*top) == NULL){
		*top = tempNode;
		(*top) -> next = NULL;
	}else{
		tempNode -> next = *top;
		*top = tempNode;
	}
}

void pushQuene(pStacknode* head,int data){
	pushStack(head,data);

}

void popStack(pStacknode* top,int *data){
	if((*top) == NULL){
		return;
	}
	pStacknode tempNode = *top;
	*data = (*top) -> data;
	*top = (*top) -> next;

	free(tempNode);


}

void popQuene(pStacknode* head,int *data,pStacknode* head2){

	pStacknode tempNode = *head;

	while(tempNode != NULL){
		*head = (*head) ->next;
		popStack(&tempNode,data);
		pushStack(head2,*data);
		tempNode = *head;
	}

	popStack(head2,data);
	
}

void print(pStacknode top){
	if(top == NULL){
		return;
	}
	pStacknode tempNode = (pStacknode)malloc(sizeof(stacknode));
	tempNode = top;
	while(tempNode != NULL){
		printf("%4d",tempNode -> data);
		tempNode = tempNode ->next;
	}

}


int main(int argc, char const *argv[])
{

	pStacknode top = NULL;
	int data;
	for(int i = 0;i < 100;i++){
		pushStack(&top,i);
	}
	print(top);
	printf("%s\n","-------------" );

	popStack(&top,&data);
	print(top);
	printf("%s\n","-------------" );








	pStacknode head = NULL;
	int data2;
	for(int i = 0;i < 100;i++){
		pushQuene(&head,i);
	}
	

	print(head);
	printf("%s\n","-------------" );

	pStacknode head2 = NULL;
	popQuene(&head,&data,&head2);
	print(head2);
	return 0;
}