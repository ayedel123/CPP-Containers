#include <iostream>
#include "my_pair.h"
#include "../s21_containers.h"
#include <map>

// using namespace s21;

int main()
{
    s21::set<int> s21_set1 = {1, 2, 3, 4, 5, 6};
    s21::set<int> s21_set2 = {7};

    std::cout << "Set 1 befor swap: ";
    for (auto it = s21_set1.begin(); it != s21_set1.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::cout << "Set 2 befor swap: ";
    for (auto it = s21_set2.begin(); it != s21_set2.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Обмен значениями
    s21_set1.swap(s21_set2);

    // Проверка на содержимое после swap
    std::cout << "Set 1 after swap: ";
    for (auto it = s21_set1.begin(); it != s21_set1.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::cout << "Set 2 after swap: ";
    for (auto it = s21_set2.begin(); it != s21_set2.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl
              << s21_set1.size();

    return 0;
}
