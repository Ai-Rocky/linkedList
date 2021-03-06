#include <stdio.h>

struct Node
{
    int data;
    struct Node *next;
};
struct Node *start = NULL, *newNode, *prevNode;

void createNode ()
{
    newNode = (struct Node*)malloc(sizeof(struct Node));
    scanf("%d",&newNode->data);
    newNode->next = NULL;
}
void printList ()
{
    printf("\n      Head\n");
    printf("-------------------\n");
    printf("    %p\n",start);
    printf("-------------------\n");
    printf("       |\n       |\n");

    struct Node *print = start;
    while (print != NULL)
    {
        printf("    %p\n",print);
        printf("--------------------\n");
        printf("   %d   | %p\n",print->data,print->next);
        printf("--------------------\n");
        printf("       |\n       |\n");
        print = print->next;
    }
}
void createList ()
{
    int i, n;

    printf("Enter the number of item: ");
    scanf("%d",&n);

    for(i=0; i<n; i++)
    {
        createNode();
        if(start == NULL){
            start = newNode;
            prevNode = newNode;
        }else{
           prevNode->next = newNode;
           prevNode = newNode;
        }
    }
}
void deleteItem ()
{
    createNode();
    struct Node *search = start;

    while (search != NULL)
    {
        if(newNode->data == search->data){
            if(search == start) start = search->next;
            else prevNode->next = search->next;
            break;
        }else{
            prevNode = search;
            search = search->next;
        }
    }
}

void main ()
{
    createList();
    printList();

    printf("\nEnter the item to delete: ");
    deleteItem();

    printList();
}


