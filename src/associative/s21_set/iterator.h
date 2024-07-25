#ifndef __S21_SET_ITERATOR_ACCESS__
#define __S21_SET_ITERATOR_ACCESS__

namespace s21
{

    template <typename Key>
    typename s21_set<Key>::iterator s21_set<Key>::begin()
    {
        return rbtree_.begin();
    }

    template <typename Key>
    typename s21_set<Key>::iterator s21_set<Key>::end()
    {
        return rbtree_.end();
    }

}

#endif