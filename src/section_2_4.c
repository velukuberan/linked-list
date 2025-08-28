// inserting node into the list
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node *next;
} Node;

Node *insert_at_head(Node *head, int value);
Node *insert_at_tail(Node *head, int value);
void print_list(Node *head);

int main() {
    Node *pNodeHead;
    Node *first;

    // first = insert_at_head(pNodeHead, 10);
    // pNodeHead = insert_at_head(first, 11);

    for (int i = 16; i < 101; i++) {
        pNodeHead = insert_at_head(pNodeHead, i);
    }

    print_list(pNodeHead);

    for (int i = 101; i < 201; i++) {
        pNodeHead = insert_at_tail(pNodeHead, i);
    }

    printf("\nPrinting the tail: \n");
    print_list(pNodeHead);
    return 0;
}

Node *insert_at_head(Node *head, int value)
{
    Node *temp_node = calloc(1, sizeof(Node));
    temp_node->value = value;

    if (head == NULL) {

        return temp_node;
    }

    temp_node->next = head;
    return temp_node;
}

Node *insert_at_tail(Node *head, int value)
{
    Node *temp_node = calloc(1, sizeof(Node));
    temp_node->value = value;

    if (head == NULL) {

        return temp_node;
    }

    Node *current = head;
    
    while (current->next != NULL) current = current->next;
    current->next = temp_node;
    return head;
}

void print_list(Node *head)
{
    Node *curr = head;

    int i = 0;

    while (curr != NULL) {
        printf("Index: %d, Value: %d\n", i, curr->value);
        curr = curr->next;
        i++;
    }
}
