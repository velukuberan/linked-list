#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _linked_list {
    int data;
    struct _linked_list *next;
} LinkedList;

void print(LinkedList *);
int length(LinkedList *head);
bool contains(LinkedList *head, int value);
LinkedList* insert_at_head(LinkedList*, int);
LinkedList* insert_at_tail(LinkedList*, int);
LinkedList* delete_at_head(LinkedList*);
LinkedList* delete_at_tail(LinkedList*);
LinkedList* free_linked_list(LinkedList*);

int main() {
    LinkedList *head = NULL;

    for (int i = 1; i <= 5; i++) {
        head = insert_at_head(head, i * i);
    }

    printf("Insert At head: \n");
    print(head);
    printf("\nLength of the ll: %d\n", length(head));

    for (int i = 11; i <= 15; i++) {
        head = insert_at_tail(head, i * i);
    }

    printf("Insert At tail: \n");
    print(head);
    printf("\nLength of the ll: %d\n", length(head));

    head = free_linked_list(head);

    for (int i = 1; i <= 5; i++) {
        head = insert_at_head(head, i * i);
    }

    printf("Again Insert At head: \n");
    print(head);
    printf("\nLength of the ll: %d\n", length(head));

    for (int i = 11; i <= 15; i++) {
        head = insert_at_tail(head, i * i);
    }

    printf("Again Insert At tail: \n");
    print(head);
    printf("\nLength of the ll: %d\n", length(head));

    printf("Please enter the value to find: ");

    int find = 0;

    scanf("%d", &find);

    if (contains(head, find)) {
        printf("Value %d is present.\n", find);
    } else {
        printf("Value is not there.\n");
    }

    printf("Press any key to continue...\n");
    scanf("%d", &find);

    for (int i = 1; i < 3; i++) {
        head = delete_at_head(head);
    }

    printf("\nAfter deleting first three heads....\n");
    print(head);
    printf("\nLength of the ll: %d\n", length(head));

    for (int i = 1; i < 3; i++) {
        head = delete_at_tail(head);
    }

    printf("\nAfter deleting first three tails....\n");
    print(head);
    printf("\nLength of the ll: %d\n", length(head));

    head = free_linked_list(head);
    printf("\nLength of the ll: %d\n", length(head));

    return 0;
}


void print(LinkedList *head)
{
    LinkedList *temp = head;
    int cnt = 1;

    printf("\nDisplay the Linked List data\n");

    while (temp != NULL) {
        printf("Node %d (%p): Data => %d\n", cnt, temp, temp->data);
        temp = temp->next;
        cnt++;
    }
}

int length(LinkedList *head)
{
    LinkedList *temp = head;
    int length = 0;

    while (temp != NULL) {
        length++;
        temp = temp->next;
    }

    return length;
}

bool contains(LinkedList *head, int value)
{
    LinkedList *temp = head;

    while (temp != NULL) {
        if (temp->data == value) {
            return true;
        }

        temp = temp->next;
    }

    return false;
}

LinkedList* insert_at_head(LinkedList* head, int data)
{
    LinkedList *new_linked_list = calloc(1, sizeof(LinkedList));

    if (new_linked_list == NULL) {
        fprintf(stderr, "Memory can't be allocated.\n");
        return head;
    }

    new_linked_list->data = data;

    LinkedList *temp = head;

    if (temp == NULL) {
        return new_linked_list;
    }

    new_linked_list->next = head;
    return new_linked_list;
}

LinkedList* insert_at_tail(LinkedList* head, int data)
{
    LinkedList *new_linked_list = calloc(1, sizeof(LinkedList));

    if (new_linked_list == NULL) {
        fprintf(stderr, "Memory can't be allocated.\n");
        return head;
    }

    new_linked_list->data = data;

    LinkedList *temp = head;

    if (temp == NULL) {
        return new_linked_list;
    }

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = new_linked_list;
    return head;
}

LinkedList* delete_at_head(LinkedList* head)
{
    if (head == NULL) {
        return NULL;
    }

    LinkedList *next = head->next;
    free(head);
    return next;
}

LinkedList* delete_at_tail(LinkedList* head)
{
    if (head == NULL) {
        return NULL;
    }

    if (head->next == NULL) {
        free(head);
        return NULL;
    }

    LinkedList *temp = head;
    LinkedList *prev = NULL;

    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;
    free(temp);

    return head;
}

LinkedList* free_linked_list(LinkedList* head)
{
    printf("\nFreeing the memory.\n");
    LinkedList *temp = head;
    LinkedList *prev = NULL;

    while (temp != NULL) {
        prev = temp->next;
        free(temp);
        temp = prev;
    }

    return NULL;
}

