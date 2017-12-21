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
        printf("\nFound in %p\n",search);
    else
        printf("\nNot found\n");
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

void main ()
{
    createList();
    printList();
    searchItem();
}
