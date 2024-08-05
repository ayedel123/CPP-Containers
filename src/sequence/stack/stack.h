#ifndef CPP2_S21_CONTAINERS_2_STACK_STACK_H_
#define CPP2_S21_CONTAINERS_2_STACK_STACK_H_

#include "../../s21_containers.h"
#include "../vector/vector.h"

namespace s21
{
    template <class T>
    class stack : public vector<T>
    {
    public:
        // Members type
        using value_type = T;
        using reference = T &;
        using const_reference = const T &;
        using size_type = size_t;

        // Constructors
        stack();
        explicit stack(size_type n);
        stack(std::initializer_list<value_type> const &items);
        stack(const stack &s);
        stack(stack &&s) noexcept;
        ~stack() = default;

        // Operators
        stack &operator=(stack &&s) noexcept;

        // Element access
        const_reference top() const;

        // Capacity
        bool empty();
        size_type size();

        // Modifiers
        void push(const_reference value);
        void pop();
    };
} // namespace s21

#include "member_functions.h"
#include "element_access.h"
#include "capacity.h"
#include "modifiers.h"

#endif // CPP2_S21_CONTAINERS_2_STACK_H