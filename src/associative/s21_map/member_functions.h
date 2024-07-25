#ifndef __S21_MAP_MEMBER_FUNCTIONS__
#define __S21_MAP_MEMBER_FUNCTIONS__

namespace s21
{

    template <typename Key, typename T>
    s21_map<Key, T>::s21_map() : s21_map()
    {
        rbtree_ = RedBlackTree(PairLess, PairEqual);
    }

    template <typename Key, typename T>
    s21_map<Key, T>::s21_map(const s21_map &s) : s21_map()
    {
        for (auto it = rbtree_.begin(); it != rbtree_.end(); ++it)
        {
            rbtree_.InsertNode(*it);
        }
    }

    template <typename Key, typename T>
    s21_map<Key, T>::s21_map(std::initializer_list<value_type> const &items) : s21_map()
    {
        for (auto it = items.begin(); it != items.end(); it++)
        {
            rbtree_.InsertNode(value_type{it.first, it.second});
        }
    }

    template <typename Key, typename T>
    s21_map<Key, T>::s21_map(s21_map &&s)
    {
        this->rbtree_ = std::move(s.rbtree_);
    }

    template <typename Key, typename T>
    s21_map<Key, T> s21_map<Key, T>::operator=(s21_map &&s)
    {
        this->rbtree_ = s.rbtree_;
        s21_map<Key, T>::iterator iter = s.begin();
        while (iter != s.end())
        {
            insert(*iter);
            ++iter;
        }
        return *this;
    }

}

#endif