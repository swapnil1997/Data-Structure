#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
}*head,*join;

void insert(struct node** head,int data);
void display(struct node* head);
struct node* count(struct node* head);
void loop(struct node* head,struct node* join);

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
void loop(struct node* head,struct node* join){
    struct node* temp = head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=join;
}
void display(struct node* head){
    struct node* node = head;
    struct node* current = head->next->next;
    int loop=0;
    int count=0;
    while(node!=current){
        node=node->next;
        current=current->next->next;
        if(node==current){
        loop=1;
        break;
        }
    }
    //Finds the node from which the loop had been started.
    //GENERALLY IT IS BEING USED FOR FINDING WHETHER THERE IS ANY LOOP EXIST IN LIST OR NOT.......
    if(loop){
        current=current->next;
        while(current!=node){
            count++;
            current=current->next;
        }
        printf("%d",count);
        return;
    }
}
struct node* count(struct node* head){
    struct node* current=head;
    int count=0;
    while(count!=2){
        count++;
        current=current->next;
    }
    return current;
}
void main(){
    head=NULL;
    insert(&head,3);
    insert(&head,4);
    insert(&head,5);
    insert(&head,6);
    insert(&head,7);
    insert(&head,8);
    insert(&head,9);
    insert(&head,10);
    join = count(head);
    loop(head,join);
    display(head);
}