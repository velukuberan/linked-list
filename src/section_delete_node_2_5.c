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

    printf("\nInsert at the head (O(1) operation, quick)\n");

    for (int i = 1; i <= 5; i++) {
        head = insert_at_head(head, i * i);
    }

    print(head);

    printf("\nDelete 1 and 2 nodes (At head)\n");
    for (int i = 1; i <= 2; i++) {
        head = delete_at_head(head);
    }

    print(head);

    //
    // head = free_linked_list(head);

    printf("\nInsert at the tail (O(n) operation, expensive)\n");

    for (int i = 11; i <= 15; i++) {
        head = insert_at_tail(head, i * i);
    }

    print(head);

    printf("\nAgain Insert at the head (O(1) operation, quick)\n");

    for (int i = 25; i <= 30; i++) {
        head = insert_at_head(head, i * i);
    }

    print(head);

    printf("\nDelete 1 and 2 nodes (At Tails)\n");
    for (int i = 1; i <= 2; i++) {
        head = delete_at_tail(head);
    }

    print(head);
    head = free_linked_list(head);

    print(head);
    
    return 0;
}

void print(LinkedList *head)
{
    printf("\n*** Printing the Values in the Linked List ***\n");

    LinkedList* current = head;
    int cnt = 1;

    while (current != NULL) {
        printf("Linked List %d (%p) (Next Ptr: %p) containts value %d\n", cnt, current, current->next, current->data);
        cnt++;
        current = current->next;
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

    if (head == NULL) {
        return new_linked_list;
    }

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

    if (head == NULL) {
        return new_linked_list;
    }

    LinkedList *current = head;

    while (current->next != NULL) {
        current = current->next;
    }

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

    LinkedList *curr = head;
    LinkedList *prev = NULL;

    while (curr->next != NULL) {
        prev = curr;
        curr = curr->next;
    }

    prev->next = NULL;
    free(curr);

    return head;
}

LinkedList* free_linked_list(LinkedList *head)
{
    LinkedList *current = head;
    LinkedList *next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    return NULL;
}

