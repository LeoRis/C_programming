#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *link;
};

void count_of_nodes(struct node *head);

int main(){
    struct node *head = malloc(sizeof(struct node));
    head->data = 45;
    head->link = NULL;

    struct node *current = malloc(sizeof(struct node));
    current->data = 98;
    current->link = NULL;
    head->link = current;

    current = malloc(sizeof(struct node));
    current->data = 3;
    current->link = NULL;

    head->link->link = current;
    
    void count_of_nodes(struct node *head);

    return 0;
}

void count_of_nodes(struct node *head){
    int count = 0;
    if(head == NULL){
        printf("The list is empty!");
    }
    struct node *ptr = NULL;
    ptr = head;
    
    while(ptr != NULL){
        count++;
        ptr = ptr->link;
    }
    printf("The number of nodes is: %d", count);
}
