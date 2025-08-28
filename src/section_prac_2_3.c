#include <stdio.h>

typedef struct _node {
    int value;
    struct _node *next;
} Node;

typedef struct _addr {
    int value;
    int pincode;
    char ch[9];
} Address;

int main() {
    printf("%ld\n", sizeof(Node));
    printf("Address: %ld\n", sizeof(Address));

    Node a, b, c;
    a.value = 10;
    b.value = 20;
    c.value = 30;

    a.next = &b;
    b.next = &c;
    c.next = NULL;

    Node *pNode, *cNode;
    pNode = &a;
    cNode = pNode;

    int cnt = 0;

    while (cNode != NULL) {
        printf(
            "Index: %d, Head Node Address: %p, Current Node Address: %p\n", 
            cnt,
            pNode,
            cNode
        );
        printf("Node value: %d\n", cNode->value);
        cNode = cNode->next;
        cnt++;
    }

    return 0;
}
