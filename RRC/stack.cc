#include <stdio.h>
#include <stdlib.h>
//malloc

#define bool int
#define true 1
#define false 0

typedef struct _node {
	int data;
	struct _node* next;
}*pNode;

typedef struct _stack {
	//pNode bottom;
	pNode top;
}*pStack;

typedef struct _queue {
	pNode head;
	pNode tail;
}*pQueue;

pStack initStack() {
	pStack s = (pStack)malloc(sizeof(struct _stack));
	if(s == NULL) {
		return NULL;
	}

	//s->bottom = NULL;
	s->top = NULL;
	return s;
}

bool pushStack(pStack s,int data) {
	if(s == NULL){
		return false;
	}

	pNode node = (pNode)malloc(sizeof(pNode));

	if(node == NULL) {
		return false;
	}
	node->data = data;	
	if(s->top == NULL){
		node->next = NULL;
	}else{
		node->next =s->top;
	}
	s->top = node;
}

bool transferStack(pStack s){
	if(s == NULL){
		return false;
	}
	if(s->top == NULL) {
		printf("%d  ", 0);
	}

	pNode tempNode = s->top;
	while(tempNode) {
		printf("%d  ", tempNode->data);
		tempNode = tempNode->next;
	}
	printf("\n\n");
	return true;
}

bool popStack(pStack s,int* data) {
	if(s == NULL){
		return false;
	}
	if(s->top ==NULL){
		return false;
	}
	//用tempNode临时存储，之后才可以释放
	pNode tempNode = s->top;
	*data = tempNode->data;
	s->top = s->top->next;
	free(tempNode);

	return true;
}

bool cleanStack(pStack s) {
	if(s == NULL){
		return false;
	}
	if(s->top ==NULL){
		return false;
	}
	pNode tempNode = s->top;
	while(tempNode) {
		pNode tempNode2 = tempNode;
		tempNode = tempNode->next;
		//while(tempNode2) {
		//	printf("%p %p\n", tempNode2,&tempNode2);
			free(tempNode2);
		//}
	}
	s->top = NULL;
}

bool isEmptyStack(pStack s) {
	if(s == NULL){
		return false;
	}
	if(s->top == NULL){
		return true;
	}
	return false;
}

pQueue initQueue() {
	pQueue q = (pQueue)malloc(sizeof(struct _queue));
	if(q == NULL) {
		return NULL;
	}
	q->head = NULL;
	q->tail = NULL;
	return q;
}

bool transferQueue(pQueue q){
	if(q == NULL){
		return false;
	}
	if(q->head == NULL || q->tail == NULL) {
		printf("%d  ", 0);
	}

	pNode tempNode = q->head;
	while(tempNode) {
		printf("%d  ", tempNode->data);
		tempNode = tempNode->next;
	}
	printf("\n\n");
	return true;
}

bool pushQueue(pQueue q,int data) {
	if(q == NULL){
		return false;
	}

	pNode node = (pNode)malloc(sizeof(pNode));

	if(node == NULL) {
		return false;
	}
	node->data = data;
	node->next = NULL;
	if(q->head == NULL || q->tail == NULL){
		q->head = node;
		q->tail = node;
		return true;
	}else{		
		q->tail->next = node;		
		q->tail = node;
		return true;
	}
	
}

bool popQueue(pQueue q,int* data) {
	if(q == NULL){
		return false;
	}
	if(q->head ==NULL || q->tail == NULL){
		return false;
	}
	pNode tempNode = q->head;
	*data = q->head->data;
	q->head = q->head->next;
	free(tempNode);
	return true;
}

bool cleanQueue(pQueue q) {
	if(q == NULL){
		return false;
	}
	if(q->head ==NULL || q->tail == NULL){
		return false;
	}
	pNode tempNode = q->head;
	while(tempNode) {
		pNode tempNode2 = tempNode;
		tempNode = tempNode->next;
		free(tempNode2);
	}
	q->head = NULL;
	q->tail = NULL;
	return true;
}

bool isEmptyQueue(pQueue q) {
	if(q == NULL){
		return false;
	}
	if(q->head ==NULL || q->tail == NULL){
		return true;
	}
	return false;
}

int main(int argc, char const *argv[])
{
	/* code */
	pStack s = initStack();
	for(int i=0;i<100;i++){
		pushStack(s,i);
	}
	transferStack(s);

	int data;
	popStack(s,&data);
	transferStack(s);
	//d是十进制数
	printf("%d\n",data);

	cleanStack(s);
	transferStack(s);

	printf("%d\n",isEmptyStack(s));
	

	//队列
	pQueue q = initQueue();
	for(int i=0;i<100;i++){
		pushQueue(q,i);
	}
	transferQueue(q);

	for (int i = 0; i < 3; ++i)
	{
		int data;
		popQueue(q,&data);
		transferQueue(q);
		printf("%d\n",data);
	}

	cleanQueue(q);
	transferQueue(q);

	printf("%d\n",isEmptyQueue(q));
	

	return 0;
}