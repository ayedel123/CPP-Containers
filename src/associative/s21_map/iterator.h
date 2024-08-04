#ifndef CPP2_S21_CONTAINERS_1_ASSOCIATIVE_S21_MAP_ITERATOR_ACCESS_H_
#define CPP2_S21_CONTAINERS_1_ASSOCIATIVE_S21_MAP_ITERATOR_ACCESS_H_

namespace s21
{

    template <typename Key, typename T>
    typename map<Key, T>::iterator map<Key, T>::begin()
    {
        return rbtree_.Begin();
    }

    template <typename Key, typename T>
    typename map<Key, T>::iterator map<Key, T>::end()
    {
        return rbtree_.End();
    }

    template <typename Key, typename T>
    typename map<Key, T>::const_iterator map<Key, T>::begin() const
    {
        return rbtree_.cBegin();
    }

    template <typename Key, typename T>
    typename map<Key, T>::const_iterator map<Key, T>::end() const
    {
        return rbtree_.cEnd();
    }

}

#endif