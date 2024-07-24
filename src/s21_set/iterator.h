#ifndef __S21_SET_ITERATOR_ACCESS__
#define __S21_SET_ITERATOR_ACCESS__

namespace s21
{

    template <typename key_type>
    typename s21_set<key_type>::iterator s21_set<key_type>::begin()
    {
        return rbtree_.begin();
    }

    template <typename key_type>
    typename s21_set<key_type>::iterator s21_set<key_type>::end()
    {
        return rbtree_.end();
    }

}

#endif