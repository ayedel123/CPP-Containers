#ifndef CPP2_S21_CONTAINERS_1_ASSOCIATIVE_S21_SET_MAP_LOOKUP_H_
#define CPP2_S21_CONTAINERS_1_ASSOCIATIVE_S21_SET_MAP_LOOKUP_H_

namespace s21
{

    template <typename Key>
    typename set<Key>::iterator set<Key>::find(const Key &key)
    {
        return rbtree_.Find(key);
    }

    template <typename Key>
    bool set<Key>::contains(const Key &key)
    {
        return (find(key) != end());
    }

}

#endif