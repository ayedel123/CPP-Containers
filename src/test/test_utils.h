#ifndef CPP2_S21_CONTAINERS_1_TEST_TEST_UTILS_H_
#define CPP2_S21_CONTAINERS_1_TEST_TEST_UTILS_H_

#include <type_traits>
#include <utility>
#include <map>

template <typename Iterator, typename = void>
struct HasFirstAndSecond : std::false_type
{
};

template <typename Iterator>
struct HasFirstAndSecond<Iterator,
                         std::void_t<decltype(std::declval<Iterator>().first),
                                     decltype(std::declval<Iterator>().second)>>
    : std::true_type
{
};

namespace s21
{

    template <typename T, typename U>
    void AssertContainerEquality(const T &first_container,
                                 const U &second_container)
    {
        ASSERT_EQ(first_container.empty(), second_container.empty());
        ASSERT_EQ(first_container.size(), second_container.size());

        auto first_iter = first_container.begin();
        typename U::const_iterator second_iter = second_container.begin();
        while (first_iter != first_container.end())
        {
            if constexpr (HasFirstAndSecond<decltype(first_iter)>::value &&
                          HasFirstAndSecond<decltype(second_iter)>::value)
            {
                ASSERT_EQ(first_iter->first, second_iter->first);
                ASSERT_EQ(first_iter->second, second_iter->second);
            }
            else
            {
                ASSERT_EQ(*first_iter, *second_iter);
            }
            ++first_iter;
            ++second_iter;
        }
    }

    template <typename T>
    void CompareNodePointers(Node<T> *node_1, Node<T> *node_2)
    {
        if (node_1 != node_2)
        {
            ASSERT_EQ(*(node_1->key), *(node_2->key));
            ASSERT_EQ(node_1->color, node_2->color);
        }
        else
            ASSERT_EQ(node_1, node_2);
    }

    template <typename T, typename U>
    void AssertTreeEquality(const T &rbt1, U rbt2) // second is std::set<Node>
    {
        ASSERT_EQ(rbt1.Empty(), rbt2.empty());
        ASSERT_EQ(rbt1.Size(), rbt2.size());
        auto first_iter = rbt1.cBegin();
        auto second_iter = rbt2.begin();
        while (first_iter != rbt1.cEnd())
        {
            ASSERT_EQ(*first_iter, *((*second_iter).key));
            ASSERT_EQ(first_iter.GetNode().color, (*second_iter).color);
            CompareNodePointers(first_iter.GetNode().left, (*second_iter).left);
            CompareNodePointers(first_iter.GetNode().right, (*second_iter).right);
            CompareNodePointers(first_iter.GetNode().parent, (*second_iter).parent);

            ++first_iter;
            ++second_iter;
        }
    }

}

#endif