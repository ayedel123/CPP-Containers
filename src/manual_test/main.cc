#include <iostream>
#include "my_pair.h"
#include "../s21_containers.h"
#include <map>

// using namespace s21;

int main()
{
    s21::multiset<int> s21_multiset1 = {1, 2, 3, 4, 5, 6};
    s21::multiset<int> s21_multiset2 = {7, 9, 2};
    s21_multiset1.merge(s21_multiset2);

    return 0;
}
