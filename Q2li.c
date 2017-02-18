
#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node* next;
}*head;

void insert(struct node** head,int data);
void display(struct node* head);
int count(struct node* head);
void find(struct node* head,int d,int n);

void insert(struct node** head,int data){
    struct node* p = (struct node*)malloc(sizeof(struct node));
    if(*head==NULL){
        *head=p;
        (*head)->data=data;
        (*head)->next=NULL;
    }else{
    p->data=data;
    p->next=*head;
    *head=p;
    }
}
void display(struct node* head){
    struct node* node = head;
    while(node!=NULL){
        printf("%d->",node->data);
        node=node->next;
    }
}
int count(struct node* head){
    struct node* current=head;
    int count=0;
    if(head==NULL){
        return 0;
    }
    do{
        count++;
        current=current->next;
    }while(current!=NULL);
    return count;
}
void find(struct node* head,int d,int n){
    int k = d-n-1;
    struct node* node = head;
    while(k){
        node=node->next;
        k--;
    }
    printf("%d",node->data);
}
void main(){
    int d,n;
    head=NULL;
    insert(&head,4);
    insert(&head,3);
    insert(&head,2);
    insert(&head,1);
    display(head);
    d=count(head);
    printf("\nNumber of node want to delete : ");
    scanf("%d",&n);
    find(head,d,n);
}