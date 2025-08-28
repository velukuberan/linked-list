#include <stdio.h>

int main() {
    int a = 10;
    int *p = NULL;
    printf("Value of a: %d, Value of p: %p, Address of p itself: %p\n", a, p, &p);

    p = &a;
    printf("Value of a: %d, Value of p(address of a): %p, ", a, p);  
    printf("Value at the address of P: %d, Address of P itself: %p\n", *p, &p);
    return 0;
}
