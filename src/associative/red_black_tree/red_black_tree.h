#ifndef CPP2_S21_CONTAINERS_1_ASSOCIATIVE_RED_BLACK_TREE_RED_BLACK_TREE_H
#define CPP2_S21_CONTAINERS_1_ASSOCIATIVE_RED_BLACK_TREE_RED_BLACK_TREE_H

#include <iostream>
#include <queue>
#include <limits>

namespace s21
{

    enum NodeColors
    {

        black_node = false,
        red_node = true
    };

    template <typename Key>
    struct Node
    {
        Key *key;
        Node<Key> *left = nullptr;
        Node<Key> *right = nullptr;
        Node<Key> *parent = nullptr;
        int color = black_node;

        ~Node()
        {
            delete key;
        }
        bool operator<(const Node<Key> &other) const
        {
            return *key < *other.key;
        }
    };

    template <typename Key>
    class RBTree
    {

    public:
        class Iterator;
        class ConstIterator;

    public:
        using value_type = Key;
        using size_type = size_t;
        using difference_type = std::ptrdiff_t;
        using reference = value_type &;
        using const_reference = const value_type &;
        using pointer = Key *;
        using const_pointer = const pointer;
        using iterator = Iterator;
        using const_iterator = ConstIterator;

        size_type size_ = 0;

        Node<Key> *root = nullptr;

    public:
        bool (*Less)(const Key &v1, const Key &v2) = nullptr;
        bool (*Equal)(const Key &v1, const Key &v2) = nullptr;

    public:
        RBTree() : Less([](const Key &v1, const Key &v2)
                        { return v1 < v2; }),
                   Equal([](const Key &v1, const Key &v2)
                         { return v1 == v2; }) {}
        RBTree(bool (*lessFn)(const Key &, const Key &), bool (*equalFn)(const Key &, const Key &))
            : Less(lessFn), Equal(equalFn) {}

        RBTree(bool allow_equal);

        RBTree(const RBTree &other);
        RBTree(RBTree<Key> &&other) noexcept;

        ~RBTree();

        RBTree<Key> &operator=(const RBTree &other);
        RBTree<Key> &operator=(RBTree &&other);

        // Set compair functions for Ket type
        void SetComparisonFunctions(bool (*lessFn)(const Key &v1, const Key &v2), bool (*equalFn)(const Key &v1, const Key &v2))
        {
            Less = lessFn;
            Equal = equalFn;
        }

        // Swap idk
        void Swap(RBTree<Key> &first, RBTree<Key> &second) noexcept;

        // Search functions
        Node<Key> *RecursiveSearch(Node<Key> *parent, Key key);
        iterator Find(const Key &key);

        // Capacity
        size_type Size() const;
        bool Empty() const;
        size_type MaxSize() const;

        // Assign
        void Assign(iterator *iter, Key value);

        // Insert
        std::pair<RBTree<Key>::iterator, bool> InsertRecursive(Node<Key> *parent, Node<Key> *child);
        std::pair<RBTree<Key>::iterator, bool> Insert(const Key key);
        void InsCase1(Node<Key> *node);
        void InsCase2(Node<Key> *node);
        void InsCase3(Node<Key> *node);
        void InsCase4(Node<Key> *node);
        void InsCase5(Node<Key> *node);

        // Remove
        void Remove(Key key);
        void DelCase1(Node<Key> *node);
        void DelCase2(Node<Key> *node);
        void DelCase3(Node<Key> *node);
        void DelCase4(Node<Key> *node);
        void DelCase5(Node<Key> *node);
        void DelCase6(Node<Key> *node);

        // Clear
        void Clear();

        // Remove Helpers
        Node<Key> *HandleTwoChildren(Node<Key> *tmp);
        void HandleChildFree(Node<Key> *tmp);
        void HanldeIfChild(Node<Key> *tmp, Node<Key> *child);

        void LRNdelete(Node<Key> *tmp);

        // Iterators
        iterator Begin();
        iterator End();
        ConstIterator cBegin() const;
        ConstIterator cEnd() const;

        // Iterator walkers
        Node<Key> *GetMin(Node<Key> *tmp) const;
        Node<Key> *GetMax(Node<Key> *tmp) const;
        Node<Key> *Next(Node<Key> *tmp);
        Node<Key> *Previous(Node<Key> *tmp);

        // Helpers
        void RotateLeft(Node<Key> *node);
        void RotateRight(Node<Key> *node);

        Node<Key> *GetGrandpa(Node<Key> *node);
        Node<Key> *GetUncle(Node<Key> *node);
        Node<Key> *Sibling(Node<Key> *node);

        void
        PrintTree(Node<Key> *root)
        {
            if (root == nullptr)
            {
                return;
            }

            std::queue<Node<Key> *> q;
            q.push(root);

            while (!q.empty())
            {
                int nodeCount = q.size();

                while (nodeCount > 0)
                {
                    Node<Key> *node = q.front();
                    q.pop();
                    if (node)
                    {
                        if (node->color == 1)
                        {
                            // Устанавливаем красный цвет для текста
                            std::cout << "\033[1;31m"; // ASCII-код для установки цвета текста в красный
                        }
                        else
                        {
                            // Устанавливаем черный цвет для текста
                            std::cout << "\033[1;30m"; // ASCII-код для установки цвета текста в черный
                        }
                        std::cout << *(node->key);  // Вывод значения узла
                        std::cout << "\033[0m "; // Сброс цвета обратно в стандартный
                        if (node->left)
                        {
                            q.push(node->left);
                        }
                        if (node->right)
                        {
                            q.push(node->right);
                        }
                    }
                    nodeCount--;
                }
                std::cout << std::endl;
            }
        }

    private:
        bool allow_equal_ = false;
    };
}
#include "tree_operations.h"
#include "insert.h"
#include "remove.h"
#include "tree_walker.h"
#include "destructor.h"
#include "iterator.h"
#include "capacity.h"

#endif