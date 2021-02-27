#include <stdio.h>

struct Node {
    int data;
    struct Node *next;
};

void print_linked_list(struct Node*);

int main() {
    /* Declare and initialise linked list of size 3 */   
    struct Node linkedList1;
    struct Node linkedList2;
    struct Node linkedList3;
    linkedList1.data = 1;
    linkedList1.next = &linkedList2;
    linkedList2.data = 2;
    linkedList2.next = &linkedList3;
    linkedList3.data = 3;
    linkedList3.next = NULL; 
    
    print_linked_list(&linkedList1);

    return 0;
}

void print_linked_list(struct Node *firstNode) {
    struct Node *curr = firstNode;
    int i = 0;
    while (curr != NULL) {
        printf("Node %d has data %d and address %p\n", i, curr->data, curr);
        curr = curr->next;
        i++;
    }

} 
