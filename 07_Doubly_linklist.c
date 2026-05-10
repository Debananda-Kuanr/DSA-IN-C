#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

// Traversal Function
void linkedListTraversal(struct Node *head)
{
    struct Node *ptr = head;

    while(ptr != NULL)
    {
        printf("Element is %d\n", ptr->data);
        ptr = ptr->next;
    }
}

// Insert at First
struct Node *insertAtFirst(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *) malloc(sizeof(struct Node));

    ptr->data = data;
    ptr->prev = NULL;
    ptr->next = head;

    if(head != NULL)
    {
        head->prev = ptr;
    }

    head = ptr;

    return head;
}

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    // Allocate memory for nodes
    head = (struct Node *) malloc(sizeof(struct Node));
    second = (struct Node *) malloc(sizeof(struct Node));
    third = (struct Node *) malloc(sizeof(struct Node));
    fourth = (struct Node *) malloc(sizeof(struct Node));

    // First node
    head->data = 4;
    head->prev = NULL;
    head->next = second;

    // Second node
    second->data = 3;
    second->prev = head;
    second->next = third;

    // Third node
    third->data = 6;
    third->prev = second;
    third->next = fourth;

    // Fourth node
    fourth->data = 1;
    fourth->prev = third;
    fourth->next = NULL;

    printf("Doubly Linked List before insertion\n");
    linkedListTraversal(head);

    head = insertAtFirst(head, 54);
    head = insertAtFirst(head, 58);
    head = insertAtFirst(head, 59);

    printf("Doubly Linked List after insertion\n");
    linkedListTraversal(head);

    return 0;
}