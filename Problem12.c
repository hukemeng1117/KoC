#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define bool int
#define true 1
#define false 0

bool Increament(char* num){
    int nTakeOver = 0;
    int length = strlen(num);

    for(int i = length - 1;i >= 0;i--){
        int nSum = num[i] - '0' +nTakeOver;
        if(i == length-1)
            nSum++;
        if(nSum >= 10){
            if(i == 0){
                return false;
            }else{
                nSum = nSum - 10;
                nTakeOver = 1;
                num[i] = nSum + '0';
            }
        }else{
            num[i] = nSum + '0';
            break;
        }

    }
    return true;

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


void print1ToMaxOfNDigits(int n){
    if(n <= 0){
        return;
    }
    char* num = (char*)malloc((n+1)*sizeof(char));
    memset(num,'0',n);
    num[n] = '\0';
    while(Increament(num)){
        printNumber(num);
        printf("%s","--------------");
    }
    free(num);
}


int main(){
    print1ToMaxOfNDigits(3);
    return 0;
}
