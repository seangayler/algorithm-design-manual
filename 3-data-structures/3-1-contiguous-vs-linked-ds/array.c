#include <stdio.h>

#define ARRAY_SIZE 10

int main() { 
    int n[ARRAY_SIZE];
    int i;    

    /* Initialise all elements of array to 0 and print their memory address */
    for (i = 0; i < ARRAY_SIZE; i++) {
        n[i] = 0;
        printf("Element %d has memory address %p.\n", i, &n[i]);
    } 

}
