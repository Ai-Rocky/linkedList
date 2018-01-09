#include <stdio.h>

struct Node
{
    int data;
    struct Node *next;
};
struct Node *start = NULL, *newNode, *preNode;

void createNode ()
{
    newNode = (struct Node*)malloc(sizeof(struct Node));
    scanf("%d",&newNode->data);
    newNode->next = NULL;
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
            preNode = newNode;
        }else{
           preNode->next = newNode;
           preNode = newNode;
        }
    }
}
void searchItem ()
{
    int item, found = 0;

    printf("\n\nEnter the item to search: ");
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
        printf("\nFound in %p location.\n",search);
    else
        printf("\nNot found\n");
}
void printList ()
{
    struct Node *print = start;
    while (print != NULL)
    {
        printf("%d ",print->data);
        print = print->next;
    }
}

void main ()
{
    createList();
    printList();
    searchItem();
}
