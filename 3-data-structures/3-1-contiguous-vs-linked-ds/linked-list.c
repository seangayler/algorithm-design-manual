#include <stdio.h>

struct Node {
    int data;
    struct Node *next;
};

void print_linked_list(struct Node*);
struct Node* search_linked_list(struct Node *node, int data);

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
    
    /* Print the linked list */
    print_linked_list(&linkedList1);
    
    /* Declare and initialise target data to find in linked list */
    int targets[2] = {2, 50};
    int num_targets = sizeof(targets)/sizeof(targets[0]);
    
    /* Search for targets in linked list */
    int i;
    struct Node *found_target;
    for (i = 0; i < num_targets; i++) {
        found_target = search_linked_list(&linkedList1, targets[i]);
        if (found_target != NULL) {
            printf("Target data %d found.\n", targets[i]);
        } else {
            printf("Target data %d not found.\n", targets[i]);
        }
    }
        
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

struct Node* search_linked_list(struct Node *node, int data) {
    if (node == NULL) {
        return NULL;
    } else if (node->data == data) {
        return node;
    } else {
        return search_linked_list(node->next, data);
    }
} 
