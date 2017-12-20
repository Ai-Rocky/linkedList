#include <stdio.h>

struct Node
{
    int data;
    struct Node *next;
};

void main ()
{
    struct Node *start = NULL, *newNode, *preNode;
    int i, n = 5;

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

    while (start != NULL)
    {
        printf("NewNode %p, Data %d | NextNode %p\n\n",start,start->data,start->next);
        start = start->next;
    }
}
