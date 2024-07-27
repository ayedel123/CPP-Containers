#ifndef __S21_MAP_LOOKUP__
#define __S21_MAP_LOOKUP__

namespace s21
{

    template <typename Key, typename T>
    typename map<Key, T>::iterator map<Key, T>::find(const Key &key)
    {
        return rbtree_.find(key);
    }

    template <typename Key, typename T>
    bool map<Key, T>::contains(const Key &key)
    {
        return ((rbtree_.find(key)) != end());
    }

}

#endif