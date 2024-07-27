#ifndef __S21_MAP_ITERATOR_ACCESS__
#define __S21_MAP_ITERATOR_ACCESS__

namespace s21
{

    template <typename Key, typename T>
    iterator map<Key, T>::begin()
    {
        return rbtree_.begin();
    }

    template <typename Key, typename T>
    iterator map<Key, T>::end()
    {
        return rbtree_.end();
    }

    template <typename Key>
    typename map<Key>::const_iterator map<Key>::begin() const
    {
        return rbtree_.cbegin();
    }

    template <typename Key>
    typename map<Key>::const_iterator map<Key>::end() const
    {
        return rbtree_.cend();
    }

}

#endif