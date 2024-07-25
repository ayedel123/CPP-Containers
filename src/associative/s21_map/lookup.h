#ifndef __S21_MAP_LOOKUP__
#define __S21_MAP_LOOKUP__

namespace s21
{

    template <typename Key, typename T>
    typename s21_map<Key, T>::iterator s21_map<Key, T>::find(const Key &key)
    {
        return rbtree_.find(key);
    }

    template <typename Key, typename T>
    bool s21_map<Key, T>::contains(const Key &key)
    {
        return ((rbtree_.find(key)) != end());
    }

}

#endif