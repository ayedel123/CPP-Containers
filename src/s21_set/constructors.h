#ifndef __S21_SET_CONSTRUCTORS__
#define __S21_SET_CONSTRUCTORS__

namespace s21
{
    template <typename key_type, typename value_type>
    s21_set<key_type, value_type>::s21_set()
    {
        
    }

    template <typename Key_type, typename value_type>
    s21_set<key_type, value_type>::s21_set(std::initializer_list<value_type> const &items) {}

    template <typename Key_type, typename value_type>
    s21_set<key_type, value_type>::s21_set(const s21_set<key_type, value_type> &s) {}

    template <typename Key_type, typename value_type>
    s21_set<key_type, value_type>::s21_set(s21_set &&s) {}

    template <typename Key_type, typename value_type>
    s21_set<key_type, value_type>::~s21_set() {}

}

#endif