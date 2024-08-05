#ifndef CPP2_S21_CONTAINERS_1_ASSOCIATIVE_S21_SET_MEMBER_FUNCTIONS_H_
#define CPP2_S21_CONTAINERS_1_ASSOCIATIVE_S21_SET_MEMBER_FUNCTIONS_H_

namespace s21
{

    template <typename Key>
    set<Key>::set(const set &s) : set()
    {
        for (auto it = s.begin(); it != s.end(); ++it)
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
        this->rbtree_ = RBTree<Key>();
        auto iter = s.begin();
        while (iter != s.end())
        {

            insert(*iter);
            ++iter;
        }
        return *this;
    }

}

#endif