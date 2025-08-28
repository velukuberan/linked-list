#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

typedef struct node node_t;

int main()
{
    node_t *head = NULL;
    head = (node_t *) malloc(sizeof(node_t));

    head->data = 100;
    head->next = NULL;

    printf("%d, %p, %p\n", head->data, head, &head);
    return 0;
}
