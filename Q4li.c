#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node* next;
}*head;
void insert(struct node** head,int data);
//struct node* reverse(struct node** head);
void display(struct node* head);
struct node* recreverse(struct node* head);

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
/*struct node* reverse(struct node** head){
    struct node *newnode=NULL;
    struct node *temp=*head;
    struct node* next;
    while(temp!=NULL){
        next=temp->next;
        temp->next=newnode;
        newnode=temp;
        temp=next;
    }
    *head=newnode;
}*/
struct node* recreverse(struct node* head){
    struct node* node=head;
    if(node==NULL){
        return NULL;
    }
    if(node->next==NULL){
        return node;
    }
    struct node* second = (head)->next;
    (head)->next=NULL;
    struct node* reverse=recreverse(second);
    (second)->next=head;
    return reverse;
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
    insert(&head,3);
    insert(&head,2);
    insert(&head,1);
  //  reverse(&head);
  head=recreverse(head);
    display(head);
}