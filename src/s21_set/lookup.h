#ifndef __S21_SET_MEMBER_FUNCTIONS__
#define __S21_SET_MEMBER_FUNCTIONS__

namespace s21
{

    template <typename key_type>
    typename s21_set<key_type>::iterator s21_set<key_type>::find(const key_type &key)
    {
        return rbtree_.find(key);
    }

    template <typename key_type>
    bool s21_set<key_type>::contains(const key_type &key)
    {
        return ((rbtree_.find(key)) != end());
    }

}

#endif