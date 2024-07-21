#ifndef __S21_MAP__
#define  __S21_MAP__


#include "../red_black_tree/red_black_tree.h"

namespace s21
{
    template <typename Key, typename T>
    class s21_map
    {
    private:
        RedBlackTree<Key, T> rbtree_;

    public:
    };
}



#endif