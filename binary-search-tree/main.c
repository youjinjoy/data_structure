#include <stdlib.h>
#include "bst.h"

int main(){
    Bst *New_Tree = InitTree(); // 트리 만들기
    InsertNode(New_Tree, InitNode(2));
    InsertNode(New_Tree, InitNode(1));
    InsertNode(New_Tree, InitNode(3));
    DeleteNode(New_Tree, SearchNode(New_Tree->root, 1));
    InorderTreeWalk(New_Tree->root);
    DeleteTree(New_Tree);
}