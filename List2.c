#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* prev;
    struct node* next;
}*head;

void insert(struct node** head,int data,int position);
void delete(struct node** head,int position);
void display(struct node* head);

void insert(struct node** head,int data,int position){
    int k=1;
    struct node *newnode,*temp;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    if(position==1){
        newnode->next=*head;
        newnode->prev=NULL;
        if(*head){
        (*head)->prev=newnode;
        }
        *head=newnode;
        return;
    }
    temp=*head;
    while(k<position-1 && temp->next!=NULL){
            k++;
            temp=temp->next;
        }
        newnode->next=temp->next;
        newnode->prev=temp;
        if(temp->next){
            temp->next->prev=newnode;
            temp->next=newnode;
            return;
        }
        if((temp->next)==NULL){
            temp->next=newnode;
            newnode->next=NULL;
        }
}
void delete(struct node** head,int position){
    int k=1;
    struct node *temp,*temp2;
    temp=*head;
    if(position==1){
        *head=(*head)->next;
        if((*head)!=NULL){
            (*head)->prev=NULL;
            free(temp);
            return;
        }
    }
        while(k<position && temp->next!=NULL){
            k++;
            temp2=temp;
            temp=temp->next;
        }
        temp2->next=temp->next;
        if(temp->next){
            temp->next->prev=temp2;
            free(temp);
            return;
        }
}
void display(struct node* head){
    if(head==NULL){
        printf("Doubly Linked List is Empty\n");
    }else{
        while(head!=NULL){
            printf("%d->",head->data);
            head=head->next;
            }
    }
}

void main(){
    head=NULL;
    insert(&head,12,1);
    insert(&head,13,2);
    insert(&head,14,2);
    delete(&head,3);
    display(head);
}