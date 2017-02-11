#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
}*head;

void insert(struct node** head,int data,int position);
void delete(struct node** head,int position);
void deleteList(struct node** head);
void display(struct node* node);

void deleteList(struct node** head){
    struct node *p,*q;
    p=*head;
    while(p){
        q=p->next;
        free(p);
        p=q;
    }
    *head=NULL;
    printf("Linked List is Successfully Empty\n");
}
void delete(struct node** head,int position){
    int k=1;
    struct node *p,*q;
    p=*head;
    if(position==1){
        *head=(*head)->next;
        free(p);
    }else{
        while(p!=NULL && k<position){
            k++;
            q=p;
            p=p->next;
        }
        if(p==NULL){
            printf("Node doesn't exist\n");
        }else{
            q->next=p->next;
            free(p);
        }
    }
}
void insert(struct node** head,int data,int position){
    int k = 1;
    struct node *p,*q,*newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    if(!newnode){
        printf("Memory Error\n");
        return;
    }
    p=*head;
    newnode->data=data;
    if(position==1){
        newnode->next=p;
        *head=newnode;
    }else{
        while(p!=NULL && k<position){
            k++;
            q=p;
            p=p->next;
        }
        q->next=newnode;
        newnode->next=p;
    }
}
void display(struct node* node){
    if(node==NULL){
        printf("List is Empty\n");
    }else{
        while(node!=NULL){
            printf("%d->",node->data);
            node=node->next;
        }
    }
}
void main(){
    int d=10;
    head = NULL;
    insert(&head,d,1);
    insert(&head,20,2);
    insert(&head,30,3);
    printf("Linked List is...\n");
    display(head);
    deleteList(&head);
}