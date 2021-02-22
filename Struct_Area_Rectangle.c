#include <stdio.h>

struct coordinates{
    int x;
    int y;
};

struct rectangle{
    struct coordinates upper_left;
    struct coordinates lower_right;
};

int area(struct rectangle r){
    int length, breadth;

    length = r.lower_right.x - r.upper_left.x;
    breadth = r.upper_left.y - r.lower_right.y;

    return length * breadth;
}

int main(){
    struct rectangle r;

    printf("Enter upper left coordinates for the rectangle:\n");
    scanf("%d %d", &r.upper_left.x, &r.upper_left.y);
    printf("Enter lower right coordinates for the rectangle:\n");
    scanf("%d %d", &r.lower_right.x, &r.lower_right.y);
    printf("The area of the triangle is %d.", area(r));
}

