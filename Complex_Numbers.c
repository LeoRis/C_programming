#include <stdio.h>

struct complex{
    float real;
    float imag;
};

typedef struct complex complex;

complex addition(complex Nr1, complex Nr2){
    complex complexSum;

    complexSum.real = Nr1.real + Nr2.real;
    complexSum.imag = Nr1.imag + Nr2.imag;

    return complexSum;
}

complex subtraction(complex *ptrNr1, complex *ptrNr2){
    complex complexSub;

    complexSub.real = (*ptrNr1).real - (*ptrNr2).real;
    complexSub.imag = (*ptrNr1).imag - (*ptrNr2).imag;

    return complexSub;
}

void multiply(complex Nr1, complex Nr2, complex *c){
    c->real = Nr1.real * Nr2.real - Nr1.imag * Nr2.imag;
    c->imag = Nr1.real * Nr2.imag - Nr1.imag * Nr2.real;
}

void print(complex *ptr){
    printf("%.2f", ptr->real);

    if(ptr->imag >= 0){
        printf("+j%.2f\n", ptr->imag);
    }else{
        printf("-j%.2f\n", abs(ptr->imag));
    }
}

int main(){
    complex a, b, c;
    printf("Insert 2 complex numbers: \n");
    printf("Number one: \n");
    printf("Real:");
    scanf("%f", &a.real);
    printf("Imaginary:");
    scanf("%f", &a.imag);
    printf("Number two: \n");
    printf("Real:");
    scanf("%f", &b.real);
    printf("Imaginary:");
    scanf("%f", &b.imag);

    printf("You have entered the following numbers: \n");
    print(&a);
    print(&b);

    printf("Their sum is: \n");
    c = addition(a, b);

    print(&c);

    printf("Their difference is: \n");
    c = subtraction(&a, &b);

    print(&c);

    printf("Their product is: \n");
    multiply(a, b, &c);

    print(&c);

    return 0;
}
