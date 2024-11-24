#include <crtdbg.h>
#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Function to free all nodes in the list
void deallocate(Node **root) {
    Node *current = *root;
    while (current != NULL) {
        Node *temp = current;
        current = current->next;
        free(temp);
    }
    *root = NULL;
}

// Function to insert a new node at the end of the list
void insert_end(Node **root, int val) {
    Node *new_node = malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Error: Memory allocation failed.\n");
        exit(1);
    }
    new_node->data = val;
    new_node->next = NULL;

    if (*root == NULL) {
        *root = new_node;
        return;
    }

    Node *current = *root;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = new_node;
}

// Function to insert a new node at the start of the list
void insert_start(Node **root, int val) {
    Node *new_node = malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Error: Memory allocation failed.\n");
        exit(3);
    }
    new_node->data = val;
    new_node->next = *root;
    *root = new_node;
}

// Function to insert a new node after a specific position
void insert_after(Node **root, int place, int val) {
    if (place < 0) {
        printf("Error: Invalid position %d.\n", place);
        return;
    }

    if (place == 0) {
        insert_start(root, val);
        return;
    }

    Node *new_node = malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Error: Memory allocation failed.\n");
        exit(5);
    }
    new_node->data = val;

    Node *current = *root;
    for (int i = 1; i < place; i++) {
        if (current == NULL || current->next == NULL) {
            printf("Error: Position %d exceeds list size.\n", place);
            free(new_node);
            return;
        }
        current = current->next;
    }

    new_node->next = current->next;
    current->next = new_node;
}

// Function to remove the first node of the list
void remove_start(Node **root) {
    if (*root == NULL) {
        printf("It's already empty.\n");
        return;
    }
    Node *current = *root;
    *root = current->next;
    free(current);
}

// Function to remove the last node of the list
void remove_end(Node **root) {
    if (*root == NULL) {
        printf("It's already empty.\n");
        return;
    }

    if (*root != NULL && (*root)->next == NULL) {  // Only one node left
        free(*root);
        *root = NULL;
        return;
    }

    Node *current = *root;
    Node *temp;
    while (current->next != NULL) {
        temp = current;
        current = current->next;
    }
    temp->next = NULL;
    free(current);
}

// Function to print the list
void print_list(Node *root) {
    Node *current = root;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Function to calculate the length of the list
int length_list(Node *root) {
    if (root == NULL) {
        return 0;
    }
    return (1 + length_list(root->next));
}
void swap_list(Node *curr){
    int temp = curr->data ;
    curr->data = curr->next->data;
    curr->next->data = temp;
}

void bubble_sort(Node **root){
    for(int i = 0 ; i< length_list(*root) ; i++){
        Node *curr = *root;
        while( curr!=NULL && curr->next != NULL){
            if(curr->data > curr->next->data){
                swap_list(curr);
            }
            curr = curr->next;
        }
    }
}


// Main function
int main() {
    Node *root = NULL;
    insert_end(&root, 15);
    insert_end(&root, 13);
    insert_end(&root, 22);
    insert_end(&root, 9);
    insert_after(&root, 1, 22);  // Inserting after index 1
    print_list(root);
    print_list(root);
    bubble_sort(&root);
    print_list(root);
    int len = length_list(root);
    printf("Length of list: %d\n", len);
    deallocate(&root);
    _CrtDumpMemoryLeaks();

    return 0;
}
