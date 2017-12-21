#include <stdio.h>

struct Node
{
    int data;
    struct Node *next;
};
struct Node *start = NULL, *newNode, *preNode;

void main ()
{
    int i, n;

    printf("Enter the number of item: ");
    scanf("%d",&n);

    for(i=0; i<n; i++)
    {
        newNode = (struct Node*)malloc(sizeof(struct Node));

        scanf("%d",&newNode->data);
        newNode->next = NULL;

        if(start == NULL){
            start = newNode;
            preNode = newNode;
        }
        else{
           preNode->next = newNode;
           preNode = newNode;
        }

    }

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
