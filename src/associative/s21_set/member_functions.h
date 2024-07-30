#ifndef __S21_SET_MEMBER_FUNCTIONS__
#define __S21_SET_MEMBER_FUNCTIONS__

namespace s21
{

    template <typename Key>
    set<Key>::set(const set &s) : set()
    {
        for (auto it = s.cbegin(); it != s.cend(); ++it)
        {
            insert(*it);
        }
    }

    template <typename Key>
    set<Key>::set(std::initializer_list<Key> const &items) : set()
    {
        for (auto it = items.begin(); it != items.end(); it++)
        {
            insert(*it);
        }
    }

    template <typename Key>
    set<Key>::set(set &&s)
    {
        this->rbtree_ = std::move(s.rbtree_);
    }

    template <typename Key>
    set<Key> set<Key>::operator=(set &&s)
    {
        this->rbtree_ = std::move(s.rbtree_);
        return *this;
    }

    template <typename Key>
    set<Key> &set<Key>::operator=(const set &s)
    {
        clear();
        this->rbtree_ = RedBlackTree<Key>();
        auto iter = s.cbegin();
        while (iter != s.cend())
        {

            insert(*iter);
            ++iter;
        }
        return *this;
    }

}

#endif