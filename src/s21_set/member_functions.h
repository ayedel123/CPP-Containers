#ifndef __S21_SET_MEMBER_FUNCTIONS__
#define __S21_SET_MEMBER_FUNCTIONS__

namespace s21
{
    template <typename key_type>
    s21_set<key_type>::s21_set()
    {
        rbtree_ = * new RedBlackTree<key_type>();
    }

    template <typename key_type>
    s21_set<key_type>::s21_set(const s21_set &s) : s21_set()
    {
        for (auto it = rbtree_.begin(); it != rbtree_.end(); ++it)
        {
            rbtree_.InsertNode(*it);
        }
    }

    template <typename key_type>
    s21_set<key_type>::s21_set(std::initializer_list<key_type> const &items) : s21_set()
    {
        for (auto it = items.begin(); it != items.end(); it++)
        {
            rbtree_.InsertNode(it);
        }
    }

}

#endif