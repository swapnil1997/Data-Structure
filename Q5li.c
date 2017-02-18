#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
}*head;

void insert(struct node** head,int data);
//void display(struct node* head);
void evenodd(struct node* head);

void insert(struct node** head,int data){
    struct node* p = (struct node*)malloc(sizeof(struct node));
    p->data=data;
    if(*head==NULL){
        *head=p;
        (*head)->next=NULL;
    }else{
        struct node* temp = *head;
        while((temp->next)!=NULL){
            temp=temp->next;
        }
        temp->next=p;
        p->next=NULL;
    }
}
/*void display(struct node* head){
    struct node* node = head;
    if(node==NULL){
        return;
    }
    display(node->next);    
    printf("%d->",node->data);
}*/
void evenodd(struct node* head){
    struct node* node = head;
    while(node){
        node = node->next->next;
    }
    if(node==NULL){
        printf("Even");
    }else{
        printf("Odd");
    }
}
void main(){
    head=NULL;
    insert(&head,1);
    insert(&head,2);
    insert(&head,3);
    insert(&head,4);
    evenodd(head);
    //display(head);
}