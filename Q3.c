#include<stdio.h>
#include<stdlib.h>
struct node{
    char data;
    struct node* prev;
    struct node* next;
};
struct node* head=NULL;
struct node* tail=NULL;

struct node* insertAtbeginD(struct node* head,char data){
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->prev=NULL;
    newnode->next=NULL;

    if(head==NULL){
        head=newnode;
        tail=newnode;
        return head;
    }
    newnode->next=head;
    head->prev=newnode;
    head=newnode;

    return head;
}
struct node* insertAtEndD(struct node* tail,char data)
{
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->prev=NULL;
    newnode->next=NULL;

    if(tail==NULL){
        head=newnode;
        tail=newnode;
        return tail;
    }
    tail->next=newnode;
    newnode->prev=tail;
    tail=newnode;
    return tail;
}
struct node* deleteAtbeginD(struct node* head){

    if(head==NULL){
        printf("list is empty\n");
        return NULL;
    }
    if(head->next==NULL){
        free(head);

        tail=NULL;
        return NULL;
    }
    struct node* temp=head;
    head=head->next;
    head->prev=NULL;
    free(temp);
    return head;
}
struct node* deleteAtEndD(struct node* tail){

    if(tail==NULL){
        printf("list is empty\n");
        return NULL;
    }
    if(tail->prev==NULL){
        free(tail);

        head=NULL;
        return NULL;
    }
    struct node* temp=tail;
    tail=tail->prev;
    tail->next=NULL;
    free(temp);
    return tail;
}
void ForwardList(struct node* head){
    if(head==NULL){
        printf("NULL\n");
    }else{
        printf("Forward list :");
    struct node* temp=head;
    while(temp!=NULL){
        printf("%c->",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
    }
}
void BackwardList(struct node* tail){
    if(tail==NULL){
        printf("NULL\n");
    }else{
        printf("Backward list :");
    struct node* temp=tail;
    while(temp!=NULL){
        printf("%c->",temp->data);
        temp=temp->prev;
    }
    printf("NULL\n");
    }
}

int main(){
    printf("Initial Double Linked list:\n");
    ForwardList(head);
    BackwardList(tail);
    printf("After insertion three nodes at beginning\n");
    head=insertAtbeginD(head,'U');
    head=insertAtbeginD(head,'G');
    head=insertAtbeginD(head,'R');
    ForwardList(head);
    BackwardList(tail);
    printf("After insertion two nodes at end\n");
    tail=insertAtEndD(tail,'K');
    tail=insertAtEndD(tail,'T');
    ForwardList(head);
    BackwardList(tail);
    printf("After deleting two nodes at beginning\n");
    head=deleteAtbeginD(head);
    head=deleteAtbeginD(head);
    ForwardList(head);
    BackwardList(tail);
    printf("After deleting two nodes at end\n");
    tail=deleteAtEndD(tail);
    tail=deleteAtEndD(tail);
    ForwardList(head);
    BackwardList(tail);


    return 0;
}


