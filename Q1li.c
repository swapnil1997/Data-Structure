
//Implementation of Stack as a Linked List...............

#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
}*head;

void insert(struct node** head,int data);
void delete(struct node** head);
void display(struct node* head);

void insert(struct node** head,int data){
    struct node* p = (struct node*)malloc(sizeof(struct node));
    p->data=data;
    if(*head==NULL){
        *head=p;
        (*head)->next=NULL;
    }else{
        p->next=*head;
        *head=p;
    }
}
void delete(struct node** head){
    if(*head==NULL){
        printf("Stack is Empty...\n");
        return;
    }
    struct node* temp=*head;
    *head=temp->next;
    free(temp);
}
void display(struct node* head){
    struct node* node = head;
    while(node!=NULL){
        printf("%d->",node->data);
        node=node->next;
    }
}

void main(){
    head=NULL;
    insert(&head,1);
    insert(&head,2);
    delete(&head);
    delete(&head);
    display(head);
}