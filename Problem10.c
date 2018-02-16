#include <stdio.h>

int numbersOfOne(int a){

    int test = 1;
    int count = 0;
    while(test){
        if(test & a){
        //if(test & a != 0){
            count++;
        }
        test = test << 1;
    }

    return count;

}

int numbersOfOne2(int a){
    int count = 0;
    while(a){
        a = a & (a-1);
        count++;
    }
    return count;

}

int main(){
    printf("%d\n",numbersOfOne(-1));
    printf("%d",numbersOfOne2(7));

    return 0;
}

