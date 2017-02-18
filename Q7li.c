#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* npx;
}*head;
void insert(struct node** head,int data);
int value(struct node* a,struct node* b);
void display(struct node* head);

void insert(struct node** head,int data){
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->npx=value(*head,NULL)
    if(*head!=NULL){
        struct node* next = value(NULL,(*head)->npx);
        (*head)->npx = value(next,newnode);
    }
    *head=newnode;
}
int value(struct node* a,struct node* b){
    return (struct  node*)((unsigned int)(a)^(unsigned int)(b));
}
void display(struct node* head){
    struct node* current = head;
    struct node* prev = NULL;
    struct node* next;
    while(current!=NULL){
        printf("%d->",current->data);
        next=value(prev,current->npx);
        prev=current;
        current=next;
    }
}
void main(){
    head=NULL;
    insert(&head,10);
    insert(&head,20);
    insert(&head,30);
    insert(&head,40);
}