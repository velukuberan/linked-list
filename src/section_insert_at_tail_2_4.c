#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
    int data;
    struct _node *next;
} Node;


void print(Node *head);
Node* insert_at_head(Node *head, int data);
Node* insert_at_tail(Node *head, int data);
Node* free_node(Node *head);

int main() {
    Node *node = NULL;

    for (int i = 1; i <= 10; i++) {
        node = insert_at_head(node, i * i);
    }

    print(node);

    printf("Now we are going to insert at the tail, but it is expensive:\n");

    for (int i = 11; i <= 20; i++) {
        node = insert_at_tail(node, i * i);
    }

    print(node);

    node = free_node(node);
    print(node);
    return 0;
}

void print(Node *head) {
    printf("\n*** Printing all values in the Node ***\n");
   
    Node *current = head;
    int cnt = 0;

    while (current != NULL) {
        printf("Node: %d (%p), Value: %d\n", cnt, current, current->data);
        current = current->next;
        cnt++;
    }
}

Node* insert_at_head(Node *head, int data)
{
    Node *new_node = calloc(1, sizeof(Node));

    if (new_node == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return head;
    }

    new_node->data = data;

    if (head == NULL) return new_node;

    new_node->next = head;
    return new_node;
}

Node* insert_at_tail(Node *head, int data)
{
    Node *new_node = calloc(1, sizeof(Node));

    if (new_node == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return head;
    }

    new_node->data = data;

    if (head == NULL) return new_node;

    Node *current = head;

    while (current->next != NULL) current = current->next;

    current->next = new_node;

    return head;
}

Node* free_node(Node *head)
{
    Node *current = head;
    Node *next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    return NULL;
}

