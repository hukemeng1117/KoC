#include <stdio.h>
#include <stdlib.h>

#define bool int
#define true  1
#define false 0

#define CHECKNULL(x) if((x) == NULL) return false

typedef struct _node {
	int data;
	struct _node* next;
}*node;

typedef struct _list  {
	node head;
	node tail;
}*list;

list initList(){

	list l = (list)malloc(sizeof(struct _list));
	node n = (node)malloc(sizeof(struct _node));
	if(l == NULL || n == NULL) {
		return NULL;
	}

	n->next = NULL;

	l->head = n;
	l->tail = n;
	return l;
}

bool insertList(list l,int data){
	if(l == NULL){
		return false;
	}

	node tail = (node)malloc(sizeof(node));

	if(tail == NULL) {
		return false;
	}
	tail->data = data;
	tail->next = NULL;
	l->tail->next = tail;
	l->tail = tail;

	return true;
}

bool transferList(list l){
	if(l == NULL){
		return false;
	}
	if(l->head == NULL || l->tail == NULL) {
		return false;
	}
	if(l->head == l->tail){
		printf("%d\n", 0);
	}

	node tempNode = l->head->next;
	while(tempNode) {
		printf("%d  ", tempNode->data);
		tempNode = tempNode->next;
	}
	printf("\n\n");
	return true;
}

bool clearList(list l) {
	if(l == NULL){
		return false;
	}
	if(l->head == NULL || l->tail == NULL) {
		return false;
	}
	node tempNode = l->head;
	tempNode->next = NULL;
	l->tail = tempNode;
	return true;
}

bool getListById(list l,int id,int* data) {
	CHECKNULL(l);

	if(l->head == l->tail || l->head == NULL || l->tail == NULL) {
		return false;
	}
	int i =id;
	node tempNode = l->head->next;
	while(i){
		i--;
		CHECKNULL(tempNode->next);
		tempNode = tempNode->next;
	}
	*data = tempNode->data;
	return true;
}

bool deleteListById(list l,int id) {
	if(l == NULL){
		return false;
	}
	if(l->head == l->tail || l->head == NULL || l->tail == NULL) {
		return false;
	}

	int i =id-1;
	node tempNode = l->head->next;
	while(i){
		i--;
		CHECKNULL(tempNode->next);
		tempNode = tempNode->next;
	}
	CHECKNULL(tempNode->next);

	node tempNode2 = tempNode->next->next;
	free(tempNode->next);
	tempNode->next = tempNode2;
	return true;
}

bool deleteListByCondition(list l,bool condition(int data)) {
	if(l == NULL){
		return false;
	}
	if(l->head == l->tail || l->head == NULL || l->tail == NULL) {
		return false;
	}

	node preNode = l->head;
	node curNode = l->head->next;
	while(curNode) {
		if(condition(curNode->data)) {
			preNode->next = curNode->next;
			free(curNode);
			curNode = preNode->next;
			continue;
		}
		preNode = curNode;
		curNode = curNode->next;	
	}
	return true;
}

bool filterListByCondition(list l,bool condition(int data),list newList) {
	if(l == NULL){
		return false;
	}
	if(l->head == l->tail || l->head == NULL || l->tail == NULL) {
		return false;
	}
	node curNode = l->head->next;
	while(curNode) {
		if(condition(curNode->data)) {
			insertList(newList,curNode->data);
		}
		curNode = curNode->next;	
	}
	return true;
}

bool forEachListProc(list l,int process(int data)) {
	if(l == NULL){
		return false;
	}
	if(l->head == l->tail || l->head == NULL || l->tail == NULL) {
		return false;
	}
	node tempNode = l->head->next;
	while(tempNode) {
		tempNode->data = process(tempNode->data);
		tempNode = tempNode->next;
	}
	return true;
}

bool reduceListProc(list l,int process(int data1,int data2),int* result) {
	if(l == NULL){
		return false;
	}
	if(l->head == l->tail || l->head == NULL || l->tail == NULL) {
		return false;
	}
	node tempNode = l->head->next->next;
	*result = l->head->next->data;
	while(tempNode){
		*result = process(*result,tempNode->data);
 		tempNode = tempNode->next;
	}
	return true;
}


// 二级指针
// bool filterListByCondition(list l,bool condition(int data),list newList) {
// 	if(l == NULL){
// 		return false;
// 	}
// 	if(l->head == l->tail || l->head == NULL || l->tail == NULL) {
// 		return false;
// 	}
// 	node* tempNode = &(newList->head->next);
// 	node curNode = l->head->next;
// 	while(curNode) {
// 		if(condition(curNode->data)) {
// 			*tempNode = curNode;
// 			tempNode = &(curNode->next);
// 			printf("%d ## ",curNode->data);
// 			newList->tail = curNode;
// 		}
// 		curNode = curNode->next;	
// 	}
// 	return true;

// }

bool testCondition(int data) {
	if(data > 10) {
		return true;
	}
	return false;
}

bool testCondition2(int data) {
	if(data % 2 == 1) {
		return true;
	}
	return false;
}

int testCondition3(int data) {
	return data * 10;
}

int testCondition4(int data1,int data2) {
	return data1 + data2;
}

int main(int argc, char const *argv[])
{

	list l = initList();
	for(int i = 0;i<100;i++) {
		insertList(l,i+1);
	}
	int* data = (int*)malloc(sizeof(int));
	int data2;
	getListById(l,2,data);
	getListById(l,3,&data2);
	printf("list id 2 is %d\n", *data);
	printf("list id 3 is %d\n", data2);

	transferList(l);

	deleteListById(l,4);
	transferList(l);


	deleteListByCondition(l,testCondition);
	transferList(l);


	list newList = initList();
	filterListByCondition(l,testCondition2,newList);	 
	transferList(newList);

	forEachListProc(l,testCondition3);
	transferList(l);

	int result;
	reduceListProc(l,testCondition4,&result);
	printf("%d\n",result);

	// clearList(l);
	return 0;


}