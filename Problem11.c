#include <stdio.h>
#include <assert.h>

#define bool int
#define false 0
#define true 1

bool g_InvalidInput = false;

double powerWithUnsignedExponent(double base,unsigned int absexponent){
    double result = 1.0;

    while(absexponent--){
        result = result * base;
    }
    return result;
}

double power(double base,int exponent){
    if(equal(base,0.0) && exponent <=0){
        g_InvalidInput = true;
        return 0.0;
    }
    if(exponent == 0){
        return 1;
    }
    unsigned int absexponent = (unsigned int)exponent;
    if(exponent < 0){
        absexponent = -exponent;
    }
    double result = 1.0;
    result = powerWithUnsignedExponent(base,absexponent);

    if(exponent < 0){
        result = 1/result;
    }
    return result;
}



bool equal(double num1,double num2){
    if(((num1-num2) >= -0.0000001) && ((num1-num2) <= 0.0000001)){
        return true;
    }
    return false;

}

int main(){
    printf("%lf\n",power(10,5));
}

