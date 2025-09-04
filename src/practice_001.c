#include <stdio.h>
#include <stdlib.h>

typedef struct _linkedlist {
    int data;
    struct _linkedlist *next;
} LinkedList;

void print(LinkedList *head);
LinkedList* insert_at_head(LinkedList *head, int data);
LinkedList* insert_at_tail(LinkedList *head, int data);
LinkedList* delete_at_head(LinkedList *head);
LinkedList* delete_at_tail(LinkedList *head);
LinkedList* free_linked_list(LinkedList *head);

int main() {
    LinkedList *head = NULL;
    printf("\nInserting at the head\n");

    for (int i = 1; i <= 10; i++) {
        head = insert_at_head(head, i * i);
    }

    print(head);
    
    printf("\nInserting at the tail\n");

    for (int i = 11; i <= 20; i++) {
        head = insert_at_tail(head, i * i);
    }

    print(head);

    printf("\nDeleting at the head\n");
    for (int i = 1; i <=5; i++) {
        head = delete_at_head(head);
    }
    print(head);
    
    printf("\nPrint at the tail\n");
    for (int i = 1; i <=5; i++) {
        head = delete_at_tail(head);
    }
    print(head);

    head = free_linked_list(head);
    printf("\nAfter free the list\n");
    print(head);
    return 0;
}

void print(LinkedList *head) {
    printf("*** Printing the list ***\n");
    LinkedList *current = head;
    int cnt = 1;

    while (current != NULL) {
        printf("Node: %d, data: %d\n", cnt, current->data);
        current = current->next;
        cnt++;
    }
}

LinkedList* insert_at_head(LinkedList *head, int data) {
    LinkedList *new_list = calloc(1, sizeof(LinkedList));

    if (new_list == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return head;
    }

    new_list->data = data;

    if (head == NULL) return new_list;

    new_list->next = head;
    return new_list;
}

LinkedList* insert_at_tail(LinkedList *head, int data)
{
    LinkedList *new_list = calloc(1, sizeof(LinkedList));

    if (new_list == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return head;
    }

    new_list->data = data;

    if (head == NULL) return new_list;

    LinkedList *current = head;

    while (current->next != NULL) current = current->next;

    current->next = new_list;
    return head;
}

LinkedList* delete_at_head(LinkedList *head)
{
    if (head == NULL) {
        return NULL;
    }

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

    LinkedList *current = head;
    LinkedList *prev = NULL;

    while (current->next != NULL) {
        prev = current;
        current = current->next;
    }

    prev->next = NULL;
    free(current);
    return head;
}

LinkedList* free_linked_list(LinkedList *head) {
    LinkedList *current = head;
    LinkedList *prev = NULL;

    while (current != NULL) {
        prev = current->next;
        free(current);
        current = prev;
    }

    return NULL;
}

