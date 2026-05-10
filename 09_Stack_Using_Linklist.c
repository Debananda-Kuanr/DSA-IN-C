#include <stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node * next;
};
struct node* top= NULL;

void push(int x){
    struct node * new_node = malloc(sizeof(struct node ));
    if (new_node==NULL)
    {
        printf("Stack is Full\n");
        return;
    }
    new_node->data=x;
    new_node->next=top;
    top=new_node ;
}

void pop()
{
    struct node *temp = top;
    if(temp == NULL)
    {
        printf("Stack is Empty\n");
        return;
    }

    printf("Popped Element is %d\n", top->data);
    top = top->next;
    free(temp);
}


void Display(){
    struct node *temp=top;
    if(temp==NULL){
        printf("Stack is Empty\n");
        return;
    }
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

int main(){
    push(20);
    push(50);
    push(45);
    push(10);
    printf("After Push: \n");
    Display();
    pop();
    pop();
    printf("After pop:\n");
    Display();
}