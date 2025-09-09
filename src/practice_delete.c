#include <stdio.h>
#include <stdlib.h>

typedef struct _linkedlist LinkedList;
struct _linkedlist {
    int data;
    struct _linkedlist *next;
};

void print(LinkedList *);
LinkedList* insert_at_head(LinkedList *, int);
LinkedList* insert_at_tail(LinkedList *, int);
LinkedList* delete_at_head(LinkedList *);
LinkedList* delete_at_tail(LinkedList *);
LinkedList* free_linked_list(LinkedList *);


int main() {
    printf("Welcome to another practice section of Linked List.\n");

    LinkedList *head = NULL;

    printf("\nInserting at the head.\n");
    for (int i = 1; i <= 5; i++) {
        head = insert_at_head(head, i * i * i);
    }
    print(head);

    printf("\nInserting at the tail.\n");
    for (int i = 11; i <= 15; i++) {
        head = insert_at_tail(head, i * i * i);
    }
    print(head);

    head = free_linked_list(head);
    print(head);

    return 0;
}

void print(LinkedList *head)
{
    printf("*** Printing the Linkedlist Data ***\n");
    LinkedList *current = head;
    int cnt = 1;

    while (current != NULL) {
        printf("Node %d (%p): Data %d\n", cnt, current, current->data);
        current = current->next;
        cnt++;
    }
}

LinkedList* insert_at_head(LinkedList *head, int data)
{
    LinkedList *new_linked_list = calloc(1, sizeof(LinkedList));

    if (new_linked_list == NULL) {
        fprintf(stderr, "Memory is not available.\n");
        return head;
    }

    new_linked_list->data = data;

    if (head == NULL) return new_linked_list;

    new_linked_list->next = head;
    return new_linked_list;
}

LinkedList* insert_at_tail(LinkedList *head, int data)
{
    LinkedList *new_linked_list = calloc(1, sizeof(LinkedList));

    if (new_linked_list == NULL) {
        fprintf(stderr, "Memory is not available.\n");
        return head;
    }

    new_linked_list->data = data;

    if (head == NULL) return new_linked_list;

    LinkedList *current = head;

    while (current->next != NULL) current = current->next;

    current->next = new_linked_list;

    return head;
}

LinkedList* delete_at_head(LinkedList *head)
{
    if (head == NULL) return NULL;

    LinkedList *next = head->next;
    free(head);
    return next;
}

LinkedList* delete_at_tail(LinkedList *head)
{
    if (head == NULL) return NULL;

    if (head->next == NULL) {
        free(head);
        return NULL;
    }
}

LinkedList* free_linked_list(LinkedList *head)
{
    printf("\nFreeing the memory.\n");
    LinkedList *current = head;
    LinkedList *prev = NULL;

    while (current != NULL) {
        prev = current->next;
        free(current);
        current = prev;
    }

    return NULL;
}

