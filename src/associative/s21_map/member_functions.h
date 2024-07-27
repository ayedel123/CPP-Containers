#ifndef __S21_MAP_MEMBER_FUNCTIONS__
#define __S21_MAP_MEMBER_FUNCTIONS__

namespace s21
{

    template <typename Key, typename T>
    map<Key, T>::map() : rbtree_(&map<Key, T>::PairLess, &map<Key, T>::PairEqual) {}
    template <typename Key, typename T>
    map<Key, T>::map(const map &s) : map()
    {
        for (auto it = rbtree_.begin(); it != rbtree_.end(); ++it)
        {
            rbtree_.InsertNode(*it);
        }
    }

    template <typename Key, typename T>
    map<Key, T>::map(std::initializer_list<value_type> const &items) : map()
    {
        for (auto it = items.begin(); it != items.end(); it++)
        {
            rbtree_.InsertNode(value_type{it->first, it->second});
        }
    }

    template <typename Key, typename T>
    map<Key, T>::map(map &&s) : map()
    {
        this->rbtree_ = std::move(s.rbtree_);
    }

    template <typename Key, typename T>
    map<Key, T> map<Key, T>::operator=(map &&s)
    {
        this->rbtree_ = s.rbtree_;
        map<Key, T>::iterator iter = s.begin();
        while (iter != s.end())
        {
            insert(*iter);
            ++iter;
        }
        return *this;
    }

}

#endif