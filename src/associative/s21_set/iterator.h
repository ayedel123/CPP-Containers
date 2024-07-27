#ifndef __S21_SET_ITERATOR_ACCESS__
#define __S21_SET_ITERATOR_ACCESS__

namespace s21
{

    template <typename Key>
    typename set<Key>::iterator set<Key>::begin()
    {
        return rbtree_.begin();
    }

    template <typename Key>
    typename set<Key>::iterator set<Key>::end()
    {
        return rbtree_.end();
    }

    template <typename Key>
    typename set<Key>::const_iterator set<Key>::cbegin() const
    {
        return rbtree_.cbegin();
    }

    template <typename Key>
    typename set<Key>::const_iterator set<Key>::cend() const
    {
        return rbtree_.cend();
    }

}

#endif