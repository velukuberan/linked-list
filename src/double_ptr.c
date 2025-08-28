#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
    int data;
    struct _node *link;
} NODE;

void demonstrate_pointers() {
    printf("=== Understanding Double Pointers ===\n");
    
    NODE *pNode = NULL;  // This is what we have in main()
    NODE **node = &pNode; // This simulates the parameter in append()
    
    printf("pNode value: %p\n", (void *)pNode);
    printf("pNode address: %p\n", (void *)&pNode);
    printf("node value (address of pNode): %p\n", (void *)node);
    printf("*node (value of pNode): %p\n", (void *)*node);
    
    // This is what we check in the if statement:
    printf("\nChecking if (*node == NULL):\n");
    printf("*node: %p\n", (void *)*node);
    printf("NULL: %p\n", (void *)NULL);
    printf("*node == NULL: %s\n", (*node == NULL) ? "TRUE" : "FALSE");
    
    // Now let's create a node and see what happens:
    NODE *first_node = (NODE *)malloc(sizeof(NODE));
    first_node->data = 42;
    first_node->link = NULL;
    
    // Assign through the double pointer (this modifies pNode!)
    *node = first_node;
    
    printf("\nAfter assigning *node = first_node:\n");
    printf("pNode now points to: %p\n", (void *)pNode);
    printf("*node: %p\n", (void *)*node);
    printf("pNode == *node: %s\n", (pNode == *node) ? "TRUE" : "FALSE");
    
    // Now we can access the data:
    printf("Data through pNode: %d\n", pNode->data);
    printf("Data through *node: %d\n", (*node)->data);
    printf("Data through **node: %d\n", (**node).data);  // This is also valid now!
    
    free(first_node);
}

// Your original append function with comments
void append(NODE **node, int num) {
    NODE *temp, *r;
    
    // node = address of pNode
    // *node = the actual pNode variable
    if (*node == NULL) {  // "if pNode equals NULL"
        temp = (NODE *)malloc(sizeof(NODE));
        temp->data = num;
        temp->link = NULL;
        *node = temp;  // "set pNode to point to temp"
        return;
    }
    
    // If we reach here, *node is not NULL, so we can traverse
    temp = *node;  // "start from pNode"
    while (temp->link != NULL)
        temp = temp->link;
    
    r = (NODE *)malloc(sizeof(NODE));
    r->data = num;
    r->link = NULL;
    temp->link = r;
}

int main() {
    demonstrate_pointers();
    
    printf("\n=== Testing append function ===\n");
    NODE *pNode = NULL;
    
    printf("Before first append: pNode = %p\n", (void *)pNode);
    append(&pNode, 1);
    printf("After first append: pNode = %p\n", (void *)pNode);
    printf("First node data: %d\n", pNode->data);
    
    append(&pNode, 2);
    printf("After second append, traversing list:\n");
    NODE *current = pNode;
    int count = 1;
    while (current != NULL) {
        printf("Node %d: data = %d, address = %p\n", count, current->data, (void *)current);
        current = current->link;
        count++;
    }
    
    return 0;
}
