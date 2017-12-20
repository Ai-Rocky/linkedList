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
    struct Node *node = start;
    while (node != NULL)
    {
        printf("NewNode %p, Data %d | NextNode %p\n\n",node,node->data,node->next);
        node = node->next;
    }
}
void createList ()
{
    int i, n = 5;
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
    deleteItem();
    printList();
}


