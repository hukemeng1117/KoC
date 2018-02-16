#include <stdio.h>
#include <assert.h>

#define bool int
#define false 0
#define true 1

bool g_InvalidInput = false;

double powerWithUnsignedExponent2(double base,unsigned int absexponent){
    if(absexponent == 1){
        return base;
    }
    double result = powerWithUnsignedExponent2(base,absexponent >> 1);
    result = result * result;
    if(absexponent & 0x1 == 1){
        result = result * base;
    }
    return result;
}

bool equal(double num1,double num2){
    if(((num1-num2) >= -0.0000001) && ((num1-num2) <= 0.0000001)){
        return true;
    }
    return false;

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

    result = powerWithUnsignedExponent2(base,absexponent);
    if(exponent < 0){
        result = 1/result;
    }
    return result;
}




int main(){
    printf("%lf\n",power(-10,2));
}

