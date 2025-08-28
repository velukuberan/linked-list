#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
    int data;
    struct _node *link;
} NODE;

void display(NODE *);
void append(NODE **, int);
void append_at_beg(NODE **, int);
void add_after(NODE **, int, int);
int count(NODE *);
void delete(NODE **, int);

int main()
{
    NODE *pNode = NULL;

    for (int i = 1; i <= 10; i++)
    {
        append(&pNode, i);
    }

    display(pNode);
}


void display(NODE *node)
{
    while (node != NULL)
    {
        printf("Address: %p, Data: %d, Next Node's Address: %p;\n", node, node->data, node->link);
        node = node->link;
    }
    printf("\n");
}

void append(NODE **node, int num)
{
    NODE *temp, *r;

    if (*node == NULL)
    {
        temp = (NODE *) malloc(sizeof(NODE));
        temp->data = num;
        temp->link = NULL;
        *node = temp;
        return;
    }

    temp = *node;

    while (temp->link != NULL)
        temp = temp->link;

    r = (NODE *) malloc(sizeof(NODE));
    r->data = num;
    r->link = NULL;
    temp->link = r;
}

