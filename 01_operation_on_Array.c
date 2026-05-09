#include <stdio.h>

int n;

// Traverse Function
void traverse(int arr[])
{
    int i;

    if (n == 0)
    {
        printf("Array is empty.\n");
        return;
    }

    printf("Array Elements:\n");

    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");
}

// Insert at Beginning
void insertBeginning(int arr[], int value)
{
    int i;

    for (i = n; i > 0; i--)
    {
        arr[i] = arr[i - 1];
    }

    arr[0] = value;
    n++;

    printf("Inserted at beginning.\n");
}

// Insert at End
void insertEnd(int arr[], int value)
{
    arr[n] = value;
    n++;

    printf("Inserted at end.\n");
}

// Insert at Any Position
void insertPosition(int arr[], int value, int pos)
{
    int i;

    if (pos < 0 || pos > n)
    {
        printf("Invalid position.\n");
        return;
    }

    for (i = n; i > pos; i--)
    {
        arr[i] = arr[i - 1];
    }

    arr[pos] = value;
    n++;

    printf("Inserted at position %d.\n", pos);
}

// Delete from Beginning
void deleteBeginning(int arr[])
{
    int i;

    if (n == 0)
    {
        printf("Array is empty.\n");
        return;
    }

    for (i = 0; i < n - 1; i++)
    {
        arr[i] = arr[i + 1];
    }

    n--;

    printf("Deleted from beginning.\n");
}

// Delete from End
void deleteEnd(int arr[])
{
    if (n == 0)
    {
        printf("Array is empty.\n");
        return;
    }

    n--;

    printf("Deleted from end.\n");
}

// Delete from Any Position
void deletePosition(int arr[], int pos)
{
    int i;

    if (pos < 0 || pos >= n)
    {
        printf("Invalid position.\n");
        return;
    }

    for (i = pos; i < n - 1; i++)
    {
        arr[i] = arr[i + 1];
    }

    n--;

    printf("Deleted from position %d.\n", pos);
}

// Search Function
void search(int arr[], int value)
{
    int i, found = 0;

    for (i = 0; i < n; i++)
    {
        if (arr[i] == value)
        {
            printf("Element found at position %d\n", i);
            found = 1;
            break;
        }
    }

    if (found == 0)
    {
        printf("Element not found.\n");
    }
}

// Main Function
int main()
{
    int arr[100];
    int i, choice, value, pos;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter array elements:\n");

    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    do
    {
        printf("\n----- MENU -----\n");
        printf("1. Traverse\n");
        printf("2. Insert at Beginning\n");
        printf("3. Insert at End\n");
        printf("4. Insert at Any Position\n");
        printf("5. Delete from Beginning\n");
        printf("6. Delete from End\n");
        printf("7. Delete from Any Position\n");
        printf("8. Search Element\n");
        printf("9. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                traverse(arr);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &value);

                insertBeginning(arr, value);
                break;

            case 3:
                printf("Enter value: ");
                scanf("%d", &value);

                insertEnd(arr, value);
                break;

            case 4:
                printf("Enter value: ");
                scanf("%d", &value);

                printf("Enter position: ");
                scanf("%d", &pos);

                insertPosition(arr, value, pos);
                break;

            case 5:
                deleteBeginning(arr);
                break;

            case 6:
                deleteEnd(arr);
                break;

            case 7:
                printf("Enter position: ");
                scanf("%d", &pos);

                deletePosition(arr, pos);
                break;

            case 8:
                printf("Enter element to search: ");
                scanf("%d", &value);

                search(arr, value);
                break;

            case 9:
                printf("Program exited.\n");
                break;

            default:
                printf("Invalid choice.\n");
        }

    } while (choice != 9);

    return 0;
}