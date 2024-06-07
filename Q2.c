#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
};
struct node* top=NULL;
void push(int ele){
    struct node* newnode=(struct node* )malloc(sizeof(struct node));
    newnode->data=ele;
    newnode->next=NULL;
    if(top==NULL){
        printf("%d is inserted successfully\n",ele);
        top=newnode;
    }
    else{
        newnode->next=top;
        top=newnode;
        printf("%d is inserted succesfully\n",ele);
    }
}

void pop(){
    if(top==NULL){
        printf("No elements are in stack\n");
    }
    else{
        struct node* temp=top;
        top=top->next;
        printf("%d is deleted successfully\n",temp->data);
        free(temp);
    }
}
void peek(){
    if(top==NULL){
        printf("No elements are in stack\n");
    }
    else{
        printf("Top element is %d\n",top->data);
    }
}
void display(){
    if(top==NULL){
        printf("No elements are in stack\n");
    }
    else{
        printf("stack elements are ");
        struct node* temp=top;
        while(temp!=NULL){
            printf("%d ",temp->data);
            temp=temp->next;
        }
        printf("\n");
    }
}
void Search(int ele){
    int flag=0;
    struct node* temp=top;
    while(temp!=NULL){
        if(temp->data==ele){
            flag=1;
        }
        temp=temp->next;
    }
    if(flag==1){
        printf("%d is found in stack\n",ele);
    }
    else{
        printf("%d is not found in stack\n",ele);
    }
}

int isempty(){
    if(top==NULL){
        return 1;
    }
    return 0;
}

int main(){
    push(10);
    push(20);
    push(30);
    display();
    pop();
    peek();
    display();
    int search=10;
    Search(10);
    return 0;
}