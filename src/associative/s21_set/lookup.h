#ifndef __S21_SET_MAP_LOOKUP__
#define __S21_SET_MAP_LOOKUP__

namespace s21
{

    template <typename Key>
    typename set<Key>::iterator set<Key>::find(const Key &key)
    {
        return rbtree_.find(key);
    }

    template <typename Key>
    bool set<Key>::contains(const Key &key)
    {
        return ((rbtree_.find(key)) != end());
    }

}

#endif