#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
    int value;
    char name[100];
    struct _node *next;
} Node;

void print_list(Node *pNodeHead); 
Node *insert_at_head(Node *pNode, int value);

int main() {
    Node *pHead = NULL;

    for (int i = 1; i <= 10; i++) {
        pHead = insert_at_head(pHead, i * i);
    }

    print_list(pHead);

    return 0;
}

void print_list(Node *pNodeHead) {
    printf("*** Printing the Node ***\n");
    printf("Size of Node: %lu\n", sizeof(Node));
    Node *curr = pNodeHead;
    int cnt = 0;
    while (curr != NULL) {
        printf("Node %d: value: %d\n", cnt, curr->value);
        curr = curr->next;
        cnt++;
    }
}

Node *insert_at_head(Node *pNode, int value)
{
    Node *iNode = calloc(1, sizeof(Node));
    iNode->value = value;

    if (pNode == NULL) {
        printf(
            "Node is NULL: Value: %d, pNode Address: %p, iNode Next Address: %p\n",
            value,
            pNode,
            iNode
        );
        return iNode;
    }

    iNode->next = pNode;
    printf(
        "Node is Not NULL: Value: %d, pNode Address: %p, iNode Next Address: %p\n",
        value,
        pNode,
        iNode
    );
    return iNode;
}

