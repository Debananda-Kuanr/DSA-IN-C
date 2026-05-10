#include<stdio.h>

#define SIZE 5

int stack[SIZE];
int top = -1;

// Push Function
void push(int value)
{
    if(top == SIZE - 1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        top++;
        stack[top] = value;
        printf("%d pushed into stack\n", value);
    }
}

// Pop Function
void pop()
{
    if(top == -1)
    {
        printf("Stack Underflow\n");
    }
    else
    {
        printf("%d popped from stack\n", stack[top]);
        top--;
    }
}

// Peek Function
void peek()
{
    if(top == -1)
    {
        printf("Stack is Empty\n");
    }
    else
    {
        printf("Top element is %d\n", stack[top]);
    }
}

// Display Function
void display()
{
    if(top == -1)
    {
        printf("Stack is Empty\n");
    }
    else
    {
        printf("Stack Elements are:\n");

        for(int i = top; i >= 0; i--)
        {
            printf("%d\n", stack[i]);
        }
    }
}

int main()
{
    push(10);
    push(20);
    push(30);

    display();

    peek();

    pop();

    display();

    return 0;
}