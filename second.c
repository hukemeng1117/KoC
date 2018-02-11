#include <stdio.h>
#include <stdlib.h>

typedef struct _listNode
{
    int data;
    struct _listNode* next;
}Node,*pNode;

void pushNode(pNode* pHead,int data){
    pNode tempNode = (pNode)malloc(sizeof(Node));
    
    //c语言不能用new
    tempNode ->data = data;
    tempNode ->next = NULL;
    
    if(pHead == NULL){
        pHead = &tempNode;
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
        printf("%d\n",tempNode -> data);
        tempNode = tempNode ->next;
    }
    printf("%d\n",tempNode -> data);
}

void PrintListReversingly(pNode pHead){
    if(pHead == NULL){
        return;
    }
    if(pHead -> next != NULL){
        PrintListReversingly(pHead ->next);
    }
    printf("%d\n",pHead ->data);
}

int main(int argc, char const *argv[])
{
    pNode pHead = NULL;
    
    for(int i = 0;i < 100;i++){
        pushNode(&pHead,i);
    }
    
    printLink(pHead);
    
    PrintListReversingly(pHead);
    
    return 0;
}
