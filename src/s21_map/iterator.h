#ifndef __S21_MAP_ITERATOR_ACCESS__
#define __S21_MAP_ITERATOR_ACCESS__

namespace s21
{
    

    template <typename Key, typename T>
    iterator s21_map<Key, T>::begin()
    {
        return rbtree_.begin();
    }

    template <typename Key, typename T>
    iterator s21_map<Key, T>::end()
    {
        return rbtree_.end();
    }

}

#endif