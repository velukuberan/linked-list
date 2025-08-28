#include <stdio.h>
// creating and printing linked list

typedef struct node {
    int value;
    struct node *next;
} Node;

void print_list(Node *head);

int main()
{
    Node a, b, c;
    a.value = 5;
    b.value = 51;
    c.value = 10;

    a.next = &b;
    b.next = &c;
    c.next = NULL;

    print_list(&a);

    return 0;
}


void print_list(Node *head)
{
    Node *current;
    current = head;

    int i = 0;
    while (current != NULL) {
        printf("Node: %d => Value of a: %d\n", i, current->value);
        current = current->next;
        i++;
    }
}
