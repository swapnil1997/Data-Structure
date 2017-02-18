#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
}*head;

void insert(struct node** head,int data);
void display(struct node* head);
int xor(struct node* a,struct node* b);

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
void display(struct node* head){
    int count=0;
    struct node* node= head;
    struct node* first;
    struct node* second;
    while(!node){
        count++;
        printf("%d->",node->data);
        printf("\n");
        printf("%d->",node);
        node=node->next;
    }
    while(!node){
        if(count==1){
            first=node;
        }else if(count==3){
            second=node;
        }else{
            node=node->next;
        }
    }
    first->next=xor(first,second);
    printf("\n%d",first->next);
}
int xor(struct node* a,struct node* b){
    return (struct node*) ((unsigned int)(a) ^ (unsigned int)(b));
}
void main(){
    head=NULL;
    insert(&head,1);
    insert(&head,2);
    insert(&head,3);
    insert(&head,4);
    display(head);
}