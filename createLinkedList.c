#include <stdio.h>

struct Node
{
    int data;
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

    struct Node *print = start;
    while (print != NULL)
    {
        printf("%d ",print->data);
        print = print->next;
    }
}
