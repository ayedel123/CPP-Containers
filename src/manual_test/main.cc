#include <iostream>
#include "my_pair.h"
#include "../s21_containers.h"
#include <map>

using namespace s21;

int main()
{
    // std::cout << "/\\EC\n";
    RedBlackTree<int> *rb_tree = new RedBlackTree<int>();

    rb_tree->InsertNode(5);
    rb_tree->InsertNode(4);
    rb_tree->InsertNode(15);
    rb_tree->InsertNode(12);
    rb_tree->InsertNode(9);
    rb_tree->InsertNode(17);
    rb_tree->InsertNode(3);
    rb_tree->InsertNode(1);
    rb_tree->InsertNode(7);
    rb_tree->InsertNode(2);
    rb_tree->InsertNode(6);
    // rb_tree->Remove(4);
    rb_tree->PrintTree(rb_tree->root);
    std::cout << "Sorted:" << std::endl;
    // rb_tree->Sort(nullptr);

    std::cout << std::endl
              << "Size: " << rb_tree->size() << std::endl;

    std::cout << "MaxSize: " << rb_tree->max_size() << std::endl;

    // std::map<int, int> myMap;
    // myMap[5] = 1;
    // myMap[4] = 2;
    // myMap[15] = 3;
    // myMap[12] = 4;
    // myMap[9] = 5;
    // myMap[17] = 6;
    // myMap[3] = 7;
    // myMap[1] = 8;
    // myMap[7] = 9;
    // myMap[2] = 10;
    // myMap[6] = 11;

    // for (auto it = myMap.begin(); it != myMap.end(); ++it)
    // {
    //     std::cout << "Ключ: " << it->first << std::endl;
    // }
    // std::map<int, int>::iterator iter = myMap.begin();
    // std::cout<<iter->first;

    /*RedBlackTree<int>::iterator iter = rb_tree->begin();
    std::cout << (*iter) << std::endl;
    std::cout << (*(++iter)) << std::endl;
    std::cout << (*(++iter)) << std::endl;
    std::cout << (*(++iter)) << std::endl;
    std::cout << (*(++iter)) << std::endl;
    std::cout << (*(--iter)) << std::endl;
    std::cout << (*(--iter)) << std::endl;
    */

    s21_set<int> *set = new s21_set<int>();
    std::cout << set->size() << std::endl;
    set->insert(5);
    std::cout << set->size() << std::endl;

    return 0;
}