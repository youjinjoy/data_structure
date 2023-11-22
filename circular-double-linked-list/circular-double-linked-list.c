#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int key;
    struct Node *prev;
    struct Node *next;
} Node;

Node *head = NULL;

void initNode();
void insertNode();
Node *findNode(int key);
void deleteNode(int key);

int main(void){
    initNode();
    insertNode(1);
    insertNode(5);
    insertNode(3);
    insertNode(7);
    displayList();
    deleteNode(5);
    deleteNode(1);
    deleteNode(3);
    displayList();
}

void initNode(){
    // 더미 노드 만들기
    Node *dummy = (Node *)malloc(sizeof(Node));
    dummy->next = dummy;
    dummy->prev = dummy;
    dummy->key = 0;

    // head가 dummy를 가리키도록 하기
    head=dummy;
}

void insertNode(key){
    // 더미 노드의 바로 뒤에 삽입한다.
    Node *new_node = (Node *)malloc(sizeof(Node));

    new_node -> key = key;

    new_node -> prev = head;
    new_node -> next = head->next;

    head->next->prev = new_node;
    head->next = new_node;

    // head->prev = head->prev->prev->next;
    // head->prev->next = head;
    // printf("insertNode: %d, prev: %d, next: %d\n",new_node->key, new_node->prev->key, new_node->next->key);
    // printf("head->next: %d, head->prev: %d\n\n", head->next->key, head->prev->key);
}

void displayList(){
    Node *current = head->next;
    printf("=== displayList ===\n");
    if(current->key==0){
        printf("nothing to display!\n");
    }
    while(current->key != 0){
        printf("node_key: %d\n",current->key);
        current = current->next;
    }
    printf("===================\n\n");
}

Node* findNode(key){
    Node *current = head->next;
    while(current->key!=0){
        // printf("finding... %d\n",current->key);
        if (current->key==key)
            return current;
        current=current->next;
    }

    return NULL;
}

void deleteNode(key){
    Node *node = findNode(key);
    // printf("key: %d\n",node->key);
    // printf("node의 prev: %d\n",node->prev->key);
    // printf("node의 next: %d\n",node->next->key);
    if (node!=NULL){
        node->prev->next=node->next;
        node->next->prev=node->prev;
        printf("=== node deleted (key:%d) ===\n\n", key);
    }
    else{
        printf("=== nothing to delete (key:%d)! ===\n\n", key) ;
    }
}
