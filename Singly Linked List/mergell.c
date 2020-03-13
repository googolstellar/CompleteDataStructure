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

node* mergell(node *start1, node *start2) {
    node *t1 = start1, *t2 = start2, *start3 = NULL, *last;
    while(t1 != NULL && t2 != NULL) {
        if(t1->data <= t2->data) {
            if(start3 == NULL) {
                start3 = t1;
                last = start3;
            }
            else{
                last->next = t1;
                last = last->next;
            }
            t1 = t1->next;
        }
        else {
            if(start3 == NULL) {
                start3 = t2;
                last = start3;
            }
            else{
                last->next = t2;
                last = last->next;
            }
            t2 = t2->next;            
        }  
    }

    if(t1 != NULL) {
        if(start3 == NULL)
            start3 = t1;
        else
            last->next = t1;
    }
    else{        
        if(start3 == NULL)
            start3 = t2;
        else
            last->next = t2;
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

    printf("Merging the two linked list(without creating a new linkedlist):\n");
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
