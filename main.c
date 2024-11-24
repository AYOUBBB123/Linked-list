#include <crtdbg.h>
#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
    int x;
    struct Node *next;
} Node;


void deallocate(Node **root){
    Node *curr = *root;
    while (curr != NULL){
        Node *aux = curr;
        curr = curr->next;
        free(aux);
    }
    *root = NULL;
}


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
void insert_start(Node **root, int val) {
    Node *new_node = malloc(sizeof(Node));
    if (new_node == NULL) {
        exit(3);
    }
    new_node->next = *root;
    new_node->x = val;
    *root = new_node;
}

void insert_after(Node **root,int place, int val){
    if(place < 0){
        printf("u cant give a negative number\n");
        return;
    }
    Node * new_node = malloc(sizeof(Node) );
    if(new_node == NULL){
        exit(5);
    }

    if (*root == NULL  ) {
        new_node->x = val;
        new_node->next = NULL;
        *root = new_node;
        return;
    }
    if(place == 0){
        insert_start(root,val);
        return;
    }

    Node *curr = *root;
    for(int i =1; i< place ; i++){
        if(curr->next == NULL){
            printf("u dont have that much element \n");
            return;
        }
        curr = curr->next;


    }

    new_node->next = curr->next ;
    new_node->x = val;
    curr->next = new_node;

}




int main(){
Node *root = NULL ;

    insert_end(&root ,15);
    insert_end(&root ,13);
    insert_end(&root ,12);
    insert_start(&root ,12);
    insert_after(&root,-1,22);





    for(Node *curr = root;curr != NULL;curr = curr->next){
        printf("%d\n", curr->x);

    }

    deallocate(&root);
    _CrtDumpMemoryLeaks();

    return 0;
}
