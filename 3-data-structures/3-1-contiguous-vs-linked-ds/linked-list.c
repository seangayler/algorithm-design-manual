#include <stdlib.h>
#include <stdio.h>

struct Node {
    int data;
    struct Node *next;
};

void print_linked_list(struct Node*);
struct Node* search_linked_list(struct Node*, int data);
void insert_end_of_list(struct Node*, int data);

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
    int numTargets = sizeof(targets)/sizeof(targets[0]);
    
    /* Search for targets in linked list */
    int i;
    struct Node *foundTarget;
    for (i = 0; i < numTargets; i++) {
        foundTarget = search_linked_list(&linkedList1, targets[i]);
        if (foundTarget != NULL) {
            printf("Target data %d found.\n", targets[i]);
        } else {
            printf("Target data %d not found.\n", targets[i]);
        }
    }

    /* Add element to end of linked list, then search for it to prove it's there. */
    int insertionData = 50;
    insert_end_of_list(&linkedList1, insertionData);
    printf("Inserted %d into linked list.\n", insertionData);
    foundTarget = search_linked_list(&linkedList1, insertionData);
    if (foundTarget != NULL) {
        printf("Target data %d found in the linked list after inserting.\n", insertionData); 
    } else {
        printf("Something went wrong. Target data %d not found after inserting.\n", insertionData);
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

void insert_end_of_list(struct Node *node, int data) {
    if (node->next == NULL) {
        struct Node* newNode = malloc(sizeof(struct Node));
        newNode->data = data;
        newNode->next = NULL;
        node->next = newNode;
        return;
    } else {
        return insert_end_of_list(node->next, data);
    }
}   
