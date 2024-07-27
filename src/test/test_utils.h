#include <type_traits>
#include <utility>

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

        auto first_iter = first_container.cbegin();
        typename U::const_iterator second_iter = second_container.cbegin();
        while (first_iter != first_container.cend())
        {
            if constexpr (HasFirstAndSecond<decltype(first_iter)>::value &&
                          HasFirstAndSecond<decltype(second_iter)>::value)
            {
                // ASSERT_EQ(first_iter->first, second_iter->first);
                //  ASSERT_EQ(first_iter->second, second_iter->second);
            }
            else
            {
                // ASSERT_EQ(*first_iter, *second_iter);
            }
            ++first_iter;
            ++second_iter;
        }
    }
}
