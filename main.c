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

// Function to print the list
void print_list(Node *root) {
    Node *current = root;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Main function
int main() {
    Node *root = NULL;

    insert_end(&root, 15);
    insert_end(&root, 13);
    insert_end(&root, 12);
    insert_start(&root, 12);
    insert_after(&root, 5, 22);

    print_list(root);

    deallocate(&root);
    _CrtDumpMemoryLeaks();

    return 0;
}
