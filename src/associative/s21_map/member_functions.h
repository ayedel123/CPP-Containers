#ifndef CPP2_S21_CONTAINERS_1_ASSOCIATIVE_S21_MAP_MEMBER_FUNCTIONS_H_
#define CPP2_S21_CONTAINERS_1_ASSOCIATIVE_S21_MAP_MEMBER_FUNCTIONS_H_

namespace s21
{

    template <typename Key, typename T>
    map<Key, T>::map() : rbtree_(&map<Key, T>::PairLess, &map<Key, T>::PairEqual) {}

    template <typename Key, typename T>
    map<Key, T>::map(const map &s) : map()
    {
        for (auto it = s.begin(); it != s.end(); ++it)
        {
            insert(*it);
        }
    }

    template <typename Key, typename T>
    map<Key, T>::map(std::initializer_list<value_type> const &items) : map()
    {
        for (auto it = items.begin(); it != items.end(); it++)
        {
            insert(value_type{it->first, it->second});
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
        this->rbtree_ = std::move(s.rbtree_);
        return *this;
    }

    template <typename Key, typename T>
    map<Key, T> &map<Key, T>::operator=(const map &s)
    {
        clear();
        this->rbtree_ = RBTree<value_type>(&map<Key, T>::PairLess, &map<Key, T>::PairEqual);
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