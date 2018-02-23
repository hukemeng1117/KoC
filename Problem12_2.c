
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define bool int
#define true 1
#define false 0

void print1ToMaxOfNDigits(int n){
    if(n <= 0){
        return;
    }
    char* num = (char*)malloc((n+1)*sizeof(char));
    memset(num,'0',n);
    num[n] = '\0';
    int length = strlen(num);
    for(int i = 0;i < 10;i++){
        num[0] = i + '0';
        print1ToMaxOfNDigitsRecursively(num,length,0);
    }
    free(num);
}

void print1ToMaxOfNDigitsRecursively(char* num,int length,int index){
    if(index == length-1){
        printNumber(num);
        printf("%s","--------------");
        return;
    }
    for(int i = 0;i < 10;i++){
        num[index+1] = i +'0';
        print1ToMaxOfNDigitsRecursively(num,length,index+1);
    }

}

void printNumber(char* num){
    bool isBeginning0 = true;
    int length = strlen(num);
    for(int i = 0;i < length;i++){
        if(num[i] != '0'){
            isBeginning0 = false;
        }
        if(!isBeginning0){
            printf("%c",num[i]);
        }
    }


}

int main(){
    print1ToMaxOfNDigits(3);
    return 0;
}
