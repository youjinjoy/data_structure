#include "bst.h"

int main(){
    Bst *New_Tree = InitTree(); // 트리 만들기
    InsertNode(New_Tree, InitNode(1));
    InsertNode(New_Tree, InitNode(11));
    InsertNode(New_Tree, InitNode(12));
    InsertNode(New_Tree, InitNode(31));
    InsertNode(New_Tree, InitNode(51));
    InsertNode(New_Tree, InitNode(3));
    InsertNode(New_Tree, InitNode(8));
    InsertNode(New_Tree, InitNode(1));
    DeleteNode(New_Tree, SearchNode(New_Tree->root, 1));
    InorderTreeWalk(New_Tree->root);

}