#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
    int value;
    struct _node *next;
} Node;

typedef struct _linkedList {
    Node *head;
} LinkedList;

void initializeList(LinkedList *list, int value) {
    list->head = malloc(sizeof(Node));
    list->head->value = value;
}

void insert_node(LinkedList *linkedList, Node *node, Node* new_node) {
    if (linkedList->head == NULL){
        //linkedList->head = malloc(sizeof(Node));
        linkedList->head = new_node;
    } else{
        Node * current = linkedList->head;
        while (current != NULL){
            if (current == node){
                Node *tmp;
                tmp = current->next;
           //     node->next = malloc(sizeof(Node));
                current->next = new_node;
                new_node->next = tmp;
                break;
            }
            current = current->next;
        }
    }

}

void delete_node(LinkedList * linkedList, Node* node){
    Node* current = linkedList->head;
    while (current != NULL){
        if (current->next == node ){
            free(current->next);
            current->next = current->next->next;
            break;
        }
        current = current->next;
    }
}

void print_list(LinkedList * linkedList){
    Node * current = linkedList->head;
    while (current != NULL){
        printf("%d\n", current->value);
        current = current->next;
    }
}

int main(void){

    LinkedList* linkedList = malloc(sizeof(LinkedList)) ;
  //  print_list(linkedList);
    initializeList(linkedList, 5);
    Node* node = malloc(sizeof(Node));
    node->value = 0;
    Node * new_node = malloc(sizeof(Node));
    new_node->value = 8;
    insert_node(linkedList, linkedList->head, node);
    insert_node(linkedList, linkedList->head, new_node);
    print_list(linkedList);
    printf("\n");
    delete_node(linkedList, new_node);
    print_list(linkedList);
    return 0;
}