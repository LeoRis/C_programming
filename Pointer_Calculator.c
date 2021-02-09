#include <stdio.h>
#include <malloc.h>
#include <math.h>

float opf(float x, float y){
    return x;
}

float op1(float x, float y){
    return x + y;
}

float op2(float x, float y){
    return x - y;
}

float op3(float x, float y){
    return x * y;
}

float op4(float x, float y){
    return x / y;
}

float op5(float x, float y){
    return pow(x, y);
}

int main(){

    float o1, o2, r;

    char c[2]; int dummy;

    float(*pfi)(float, float);

    printf("op1: ");
    scanf("%f", &o1);

    printf("op2: ");
    scanf("%f", &o2);

    printf("operation [+ - / * ^]: ");
    scanf("%1s", c);


    switch(*c){
        case '+': {
            pfi = op1;
            break;
        }
        case '-': {
            if(o1 > o2){
                pfi = op2;
            }else{
                pfi = opf;
            }
            break;
        }
        case '*': {
            pfi = op3;
            break;
        }
        case '/': {
            if(o2 != 0 && (o1 > o2 || o1 < o2 || o1 == o2)){
                pfi = op4;
            }else{
                pfi = opf;
            }
            break;
        }
        case '^': {
            if(o1 == o2 && o2 == 0 || o1 < 0 && modf(o2, &dummy) != 0){
                pfi = opf;
            }else{
                pfi = op5;
            }
            break;
        }
    }

    r = (*pfi)(o1, o2);

    printf("result = %f\n", r);

    return 0;
}
