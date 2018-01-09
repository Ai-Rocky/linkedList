#include <stdio.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;

} *start = NULL, *newNode, *prevNode;

void createNode ()
{
    newNode = (struct Node*)malloc(sizeof(struct Node));
    scanf("%d",&newNode->data);
    newNode->prev = NULL;
    newNode->next = NULL;
}
// Create Doubly Linked List
void createList ()
{
    int i, n;

    printf("Enter the number of item to create: ");
    scanf("%d",&n);

    for(i=0; i<n; i++)
    {
        createNode();

        if(start == NULL){
            start = newNode;
            prevNode = newNode;
        }else{
           prevNode->next = newNode;
           newNode->prev = prevNode;
           prevNode = newNode;
        }
    }
}
// Insert Item At Any Position
void insertItem ()
{
    printf("Enter The Item To Insert: ");
    createNode();
    struct Node *search = start;

    while (search != NULL)
    {
        if(newNode->data < search->data){
            newNode->next = search;
            search->prev = newNode;
            if(search == start)
                start = newNode;
            else
            {
                newNode->prev = prevNode;
                prevNode->next = newNode;
            }
            break;
        }else{
            prevNode = search;
            search = search->next;
        }
    }if (search == NULL){
        newNode->next = search;
        prevNode->next = newNode;
        newNode->prev = prevNode;
    }
}
// Delete Item From Any Position
void deleteItem ()
{
    int item;
    printf("Enter The Item To Delete: ");
    scanf("%d",&item);

    struct Node *search = start;

    while (search != NULL)
    {
        if(item == search->data){
            if(search == start)
                start = search->next;
            else
                prevNode->next = search->next;
            if(search->next != NULL)
                search->next->prev = search->prev;
            break;
        }else{
            prevNode = search;
            search = search->next;
        }
    }
}
// Search Item At Any Position
void searchItem ()
{
    int item, found = 0;

    printf("Enter the item to search: ");
    scanf("%d",&item);

    struct Node *search = start;
    while (search != NULL)
    {
        if(search->data == item){
            found = 1;
            break;
        }
        search = search->next;
    }
    if(found == 1)
        printf("\nItem Found in %p location.\n",search);
    else
        printf("\nItem Not found\n");
}
// Display All Item From Linked List
void printList ()
{
    printf("\n");
    struct Node *print = start;
    while (print != NULL)
    {
        printf("%p\n%p,%d,%p\n\n",print,print->prev,print->data,print->next);
        print = print->next;
    }
}

void main ()
{
    createList();
    insertItem();
    deleteItem();
    searchItem();
    printList ();
}

