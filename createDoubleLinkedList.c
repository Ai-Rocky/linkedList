#include <stdio.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;

} *start = NULL, *newNode, *preNode;

void main ()
{
    int i, n;

    printf("Enter the number of item: ");
    scanf("%d",&n);

    for(i=0; i<n; i++)
    {
        newNode = (struct Node*)malloc(sizeof(struct Node));

        scanf("%d",&newNode->data);
        newNode->prev = NULL;
        newNode->next = NULL;

        if(start == NULL){
            start = newNode;
            preNode = newNode;
        }
        else{
           preNode->next = newNode;
           newNode->prev = preNode;
           preNode = newNode;
        }

    }

    printf("\n\t      Head\n");
    printf("      -------------------\n");
    printf("\t    %p\n",start);
    printf("      -------------------\n\n\n");

    struct Node *print = start;
    while (print != NULL)
    {
        printf("\t    %p\n",print);
        printf("-------------------------------\n");
        printf("    %p | %d | %p\n",print->prev,print->data,print->next);
        printf("-------------------------------\n\n\n");
        print = print->next;
    }
}

