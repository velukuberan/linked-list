#include <stdio.h>


void change_by_value(int a, int b);
void change_by_address(int *a, int *b);

int main() {
    int i = 100;
    int *j = &i;
    printf("Address of i: %p, Value of i: %u\n", &i, i);
    printf("Address of i: %p, Value of i (dereference): %d\n", &i, *(&i));
    printf("Value of J (containts address of i): %p, if we dereference: %d\n", j, *j);
    printf("This will be the address of j: %p\n", &j);

    int a = 100, b = 200;
    int *aPtr = &a;
    int *bPtr = &b;

    printf("Before change by value: a: %d, b: %d\n", a, b);
    change_by_value(a, b);
    printf("After change by value: a: %d, b: %d\n", a, b);


    printf("\n\nBefore change by address: a: %d, b: %d\n", a, b);
    change_by_address(&a, &b);
    printf("After change by address: a: %d, b: %d\n", a, b);
    
    printf("\n\nBefore change by address: a: %d, b: %d\n", *aPtr, *bPtr);
    change_by_address(aPtr, bPtr);
    printf("After change by address: a: %d, b: %d\n", a, b);
    return 0;
}

void change_by_value(int a, int b)
{
    a = a + 1;
    b = b + 1;
    printf("Inside Change by Value: \n");
    printf("a: %d, b: %d\n", a, b);
}

void change_by_address(int *a, int *b)
{
    *a = *a + 1;
    *b = *b + 1;
    printf("Inside Change by Address: \n");
    printf("a: %d, b: %d\n", *a, *b);
}
