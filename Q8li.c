#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
}*head,*head_ref,*head_fi;

void insert(struct node** head,int data,struct node* head_fi);
void insert1(struct node** head_ref,int data,struct node* head_fi);
void insert2(struct node** head_fi,int data);
void display(struct node* head,struct node* head_ref);
void displayfi(struct node* head,struct node* head_ref);

void insert(struct node** head,int data,struct node* head_fi){
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
        p->next=head_fi;
    }
}
void insert1(struct node** head_ref,int data,struct node* head_fi){
    struct node* p = (struct node*)malloc(sizeof(struct node));
    p->data=data;
    if(*head_ref==NULL){
        *head_ref=p;
        (*head_ref)->next=NULL;
    }else{
        struct node* temp = *head_ref;
        while((temp->next)!=NULL){
            temp=temp->next;
        }
        temp->next=p;
        p->next=head_fi;
    }
}
void insert2(struct node** head_fi,int data){
    struct node* p = (struct node*)malloc(sizeof(struct node));
    p->data=data;
    if(*head_fi==NULL){
        *head_fi=p;
        (*head_fi)->next=NULL;
    }else{
        struct node* temp = *head_fi;
        while((temp->next)!=NULL){
            temp=temp->next;
        }
        temp->next=p;
        p->next=NULL;
    }
}
void display(struct node* head,struct node* head_ref){
    struct node* node = head;
    struct node* node1 = head_ref;
    while(node!=NULL){
        printf("%d->",node->data);
        node=node->next;
    }
}
void displayfi(struct node* head,struct node* head_ref){
    struct node* node=head;
    struct node* node1=head_ref;
    printf("\n");
    while(node && node1){
        if(node==node1){
            printf("Oops...There is a Merging Point...!!!!");
            break;
        }else{
            node=node->next;
            node1=node1->next;
        }
    }
}
void main(){
    insert2(&head_fi,6);
    insert2(&head_fi,7);
    insert(&head,1,head_fi);
    insert(&head,2,head_fi);
    insert1(&head_ref,3,head_fi);
    insert1(&head_ref,4,head_fi);
    insert1(&head_ref,5,head_fi);
    display(head,head_ref);
    displayfi(head,head_ref);
}