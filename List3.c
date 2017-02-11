#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
}*head;

void insert(struct node** head,int data);
void display(struct node* head);

void insert(struct node** head,int data){
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    struct node *current = *head;
    newnode->data=data;
    while(current->next!=*head){
        current = current->next;
    }
    if(*head==NULL){
        *head=newnode;
        (*head)->next=*head;
    }else{
        newnode->next=*head;
        current->next=newnode;
    }
}
void display(struct node* head){
    struct node* current = head;
    if(head==NULL){
        printf("Circular Linked List is not Available..\n");
        return;
    }
    do{
            printf("%d->",current->data);
            current=current->next;
    }while(current!=head);
    }    

void main(){
    head=NULL;
    insert(&head,1);
}