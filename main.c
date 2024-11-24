#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Node{
    int x;
    struct Node *next;
} Node;



void insert_end(Node **root, int val){
    Node * new_node = malloc(sizeof(Node) );
    if(new_node == NULL){
        exit(1);
    }
    new_node->next = NULL;
    new_node->x = val;
    if(*root ==NULL){
        *root = new_node;
        return;
    }
    Node *curr = *root ;
    while (curr->next != NULL){
        curr = curr->next;
    }

    curr->next = new_node;
}

int main(){
Node *root = NULL ;

    insert_end(&root ,15);
    insert_end(&root ,13);
    insert_end(&root ,12);




for(Node *curr = root;curr != NULL;curr = curr->next){
        printf("%d\n", curr->x);

    }
    return 0;
}
