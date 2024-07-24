#ifndef __S21_MAP_ELEMENT_ACCESS__
#define __S21_MAP_ELEMENT_ACCESS__

namespace s21
{

    template <typename Key, typename T>
    T &s21_map<Key, T>::at(const Key &key)
    {
        value_type *tmp = nullptr;
        if (!rbtree_.root)
        {
            throw std::out_of_range("out_of_range");
        }
        else
        {
            tmp = rbtree_.RecursiveSearch(nullptr, std::pair<Key, T>(key, rbtree_.root.second))->key;
        }
        if (!tmp)
        {
            throw std::out_of_range("out_of_range");
        }
        return tmp->second;
    }

    template <typename Key, typename T>
    T &s21_map<Key, T>::operator[](const Key &key)
    {
        return at(key);
    }

}

#endif