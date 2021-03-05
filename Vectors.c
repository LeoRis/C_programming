#include <stdio.h>

struct vector{
    float x;
    float y;
    float z;
};

typedef struct vector vector;

float scalar(vector v1, vector v2){
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

vector vector_product(vector v1, vector v2){
    vector v;

    v.x = v1.y * v2.z - v1.z * v2.y;
    v.y = v1.z * v2.x - v1.x * v2.z;
    v.z = v1.x * v2.y - v1.y * v2.x;

    return v;
}

int main(){
    vector v1;
    vector v2;

    printf("Insert vector v1: ");
    scanf("%f%f%f", &v1.x, &v1.y, &v1.z);

    printf("Insert vector v2: ");
    scanf("%f%f%f", &v2.x, &v2.y, &v2.z);

    vector v;

    v = vector_product(v1, v2);

    printf("The scalar product is: %.2f\n", scalar(v1, v2));
    printf("v1 * v2 = [%.2f, %.2f, %.2f]\n", v.x, v.y, v.z);
}
