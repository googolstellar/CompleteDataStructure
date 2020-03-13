//merge two sorted linked list by creating a new linked list
#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

node* createll() {
    node *start, *last, *temp;
    int val;
    scanf("%d", &val);
    if(val == -1) {
        start = NULL;
        return start;
    }
    else {
        start = (node*)malloc(sizeof(node));
        start->data = val;
        last = start;
    }
    scanf("%d", &val);
    while(val != -1) {
        temp = (node*)malloc(sizeof(node));
        temp->data = val;
        last->next = temp;
        last = last->next;
        scanf("%d", &val);
    }
    last->next = NULL;
    return start;
}

node* mergell(node* start1, node* start2) {
    node *temp1 = start1, *temp2 = start2, *start3 = NULL, *last, *temp3;
    while(temp1 != NULL && temp2 != NULL) {
        if(temp1->data <= temp2->data) {
            if(start3 == NULL) {
                start3 = (node*)malloc(sizeof(node));
                start3->data = temp1->data;
                last = start3;
            }
            else {
                temp3 = (node*)malloc(sizeof(node));
                temp3->data = temp1->data;
                last->next = temp3;
                last = last->next;
            }
            temp1 = temp1->next;
        }
        else {
            if(start3 == NULL) {
                start3 = (node*)malloc(sizeof(node));
                start3->data = temp2->data;
                last = start3;
            }
            else {
                temp3 = (node*)malloc(sizeof(node));
                temp3->data = temp2->data;
                last->next = temp2;
                last = last->next;
            } 
            temp2  = temp2->next;  
        }
    }
    while(temp1 != NULL) {
        if(start3 == NULL) {
            start3 = (node*)malloc(sizeof(node));
            start3->data = temp1->data;
            last = start3;
        }
        else {
            temp3 = (node*)malloc(sizeof(node));
            temp3->data = temp1->data;
            last->next = temp3;
            last = last->next;
        }
        temp1 = temp1->next;
    }
    while(temp2 != NULL) {
        if(start3 == NULL) {
            start3 = (node*)malloc(sizeof(node));
            start3->data = temp2->data;
            last = start3;
        }
        else {
            temp3 = (node*)malloc(sizeof(node));
            temp3->data = temp2->data;
            last->next = temp3;
            last = last->next;
        }
        temp2 = temp2->next;
    }
    return start3;
}

void display(node* t) {
    if(t == NULL) {
        printf("Empty Linked list!\n");
    }
    while(t != NULL) {
        printf("%d ", t->data);
        t = t->next;
    }
    return;
}


int main () {
    node *start1, *start2, *start3;
    printf("LinkedList 1:\n");
    printf("Enter the value in linked list(input excepted till -1 pressed)\n");
    start1 = createll();
    printf("LinkedList 2:\n");
    printf("Enter the value in linked list(input excepted till -1 pressed)\n");
    start2 = createll();

    printf("Merging the two linked list:\n");
    start3 = mergell(start1, start2);

    // printf("Displaying First linked list:\n");
    // display(start1);
    // printf("Displaying Second linked list:\n");
    // display(start2);
    printf("Displaying Merged linkedlist:\n");
    display(start3);    
    printf("\n");
    return 0;
}