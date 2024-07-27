#ifndef __S21_SET_MEMBER_FUNCTIONS__
#define __S21_SET_MEMBER_FUNCTIONS__

namespace s21
{

    template <typename Key>
    set<Key>::set(const set &s) : set()
    {
        for (auto it = rbtree_.begin(); it != rbtree_.end(); ++it)
        {
            rbtree_.InsertNode(*it);
        }
    }

    template <typename Key>
    set<Key>::set(std::initializer_list<Key> const &items) : set()
    {
        for (auto it = items.begin(); it != items.end(); it++)
        {
            rbtree_.InsertNode(it);
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
        this->rbtree_ = s.rbtree_;
        set<Key>::iterator iter = s.begin();
        while (iter != s.end())
        {
            insert(*iter);
            ++iter;
        }
        return *this;
    }

}

#endif