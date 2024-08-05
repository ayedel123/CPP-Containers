#include <iostream>
#include "my_pair.h"
#include "../s21_containers.h"
#include <map>

using namespace s21;

int main()
{
    std::cout << "/\\EC\n";
    RBTree<int> *rb_tree = new RBTree<int>();
    // CoolPair <int,int> * coolPair = new CoolPair<int,int>();

    rb_tree->Insert(5);
    rb_tree->Insert(4);
    rb_tree->Insert(15);
    rb_tree->Insert(12);
    rb_tree->Insert(9);
    rb_tree->Insert(17);
    rb_tree->Insert(3);
    rb_tree->Insert(1);
    rb_tree->Insert(7);
    rb_tree->Insert(2);
    rb_tree->Insert(6);
    rb_tree->Insert(8);
    rb_tree->Remove(9);

    // rb_tree->Remove(4);
    rb_tree->PrintTree(rb_tree->root);

    return 0;
}
