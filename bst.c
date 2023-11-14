#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

/* 노드 생성*/
Node *InitNode(int key){
    Node *node = (Node *)malloc(sizeof(Node));
    node->key = key;
    node->parent = NULL;
    node->left = NULL;
    node->right = NULL;
}
/* 트리 생성 */
Bst *InitTree(){
    Bst *tree = (Bst *)malloc(sizeof(Bst));
    tree->root = NULL;
    tree->nil = NULL;
}

/* 중위 순회 */
void InorderTreeWalk(Node *node)
{
    if (node != NULL)
    {
        InorderTreeWalk(node->left);
        printf("%d ", node->key);
        InorderTreeWalk(node->right);
    }
}

/* 노드 검색 */
Node *SearchNode(Node *root, int key)
{
    Node *node = root;
    if (node == NULL || key == node->key)
        return node;
    if (key < node->key)
        return SearchNode(node->left, key);
    else
        return SearchNode(node->right, key);
}

/* 최소 원소 반환 */
Node *FindMinmum(Node *node)
{
    while (node->left != NULL)
        node = node->left;
    return node;
}

/* 최대 원소 반환*/
Node *FindMaximum(Node *node)
{
    while (node->right != NULL)
        node = node->right;
    return node;
}

/* Successor 반환 */
Node *FindSuccessor(Node *node)
{
    if (node-> right != NULL)
        return FindMinmum(node->right);
    Node *y = node->parent;
    while (y != NULL && node == y->right)
    {
        node = y;
        y = y->parent;
    }
    return y;
}

/* Predecessor 반환 */
Node *FindPredecessor(Node *node)
{
    if (node-> left != NULL)
        return FindMaximum(node->left);
    Node *y = node->parent;
    while (y != NULL && node == y->left)
    {
        node = y;
        y = y->parent;
    }
    return y;
}

/* 삽입 */
void InsertNode(Bst *tree, Node *node)
{
    Node *y = NULL;
    Node *x = tree->root;
    while (x != NULL)
    {
        y = x;  // y에 x 이전 값 계속 저장
        if (node->key < x->key)
            x = x->left;
        else
            x = x->right;
    }
    node->parent = y;
    if (y == NULL)
        tree->root = node;
    else if (node->key < y->key)
        y->left = node;
    else
        y->right = node;
}

/* 이식 */
void TransplantNode(Bst *tree, Node *old_node, Node *new_node)
{
    if (old_node->parent == NULL)
        tree->root = new_node;
    else if (old_node == old_node->parent->left)
        old_node->parent->left = new_node;
    else
        old_node->parent->right = new_node;
    if (new_node != NULL)
        new_node->parent = old_node->parent;
}

/* 삭제 */
void DeleteNode(Bst *tree, Node *node)
{
    Node *y;
    if (node->left == NULL)
        TransplantNode(tree, node, node->right);
    else if (node->right == NULL)
        TransplantNode(tree, node, node->left);
    else
        y = FindMinmum(node->right);
        if (y->parent != node)
            TransplantNode(tree, y, y->right);
            y->right = node->right;
            y->right->parent = y;
        TransplantNode(tree, node, y);
        y->left = node->left;
        y->left->parent = y;
}