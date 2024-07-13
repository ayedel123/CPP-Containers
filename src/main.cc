#include <iostream>
#include "my_pair.h"
#include "red_black_tree.h"

int main()
{
    std::cout << "/\\EC\n";
    RedBlackTree *rb_tree = new RedBlackTree();

    rb_tree->InsertNode(5);
    rb_tree->InsertNode(4);
    rb_tree->InsertNode(15);
    rb_tree->InsertNode(12);
    rb_tree->InsertNode(9);
    rb_tree->InsertNode(17);
    rb_tree->InsertNode(3);
    rb_tree->InsertNode(1);

    rb_tree->PrintTree(rb_tree->root);

    return 0;
}