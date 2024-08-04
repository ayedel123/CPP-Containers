#ifndef CPP2_S21_CONTAINERS_1_ASSOCIATIVE_S21_MAP_ELEMENT_ACCESS_H_
#define CPP2_S21_CONTAINERS_1_ASSOCIATIVE_S21_MAP_ELEMENT_ACCESS_H_

namespace s21
{

    template <typename Key, typename T>
    T &map<Key, T>::at(const Key &key)
    {
        if (empty())
        {
            throw std::out_of_range("out_of_range");
        }
        auto tmp = rbtree_.Find(MakePhantomPain(key));
        if (tmp == end())
        {
            throw std::out_of_range("out_of_range");
        }

        return tmp->second;
    }

    template <typename Key, typename T>
    T &map<Key, T>::operator[](const Key &key)
    {
        return at(key);
    }

}

#endif