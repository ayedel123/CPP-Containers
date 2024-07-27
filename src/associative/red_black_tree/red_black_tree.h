#ifndef __RED_BLACK_TREE__
#define __RED_BLACK_TREE__

#include <iostream>
#include <queue>
#include <limits>

namespace s21
{

    enum NodeColors
    {

        black_node,
        red_node,
        nil_node
    };

    template <typename Key>
    struct TreeNode
    {
        Key key;
        TreeNode<Key> *left = nullptr;
        TreeNode<Key> *right = nullptr;
        TreeNode<Key> *parent = nullptr;
        bool color = black_node;
    };

    template <typename Key>
    class RedBlackTree
    {

    private:
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

    private:
        bool (*Less)(const Key &v1, const Key &v2) = nullptr;
        bool (*Equal)(const Key &v1, const Key &v2) = nullptr;

    public:
        RedBlackTree() : Less([](const Key &v1, const Key &v2)
                              { return v1 < v2; }),
                         Equal([](const Key &v1, const Key &v2)
                               { return v1 == v2; }) {}

        TreeNode<Key> *root = nullptr;

        TreeNode<Key> *RecursiveSearch(TreeNode<Key> *parent, Key key);
        iterator Find(const Key &key);

        void RotateLeft(TreeNode<Key> *node);
        void RotateRight(TreeNode<Key> *node);
        void SwapColors();

        TreeNode<Key> *GetGrandpa(TreeNode<Key> *node);
        TreeNode<Key> *GetUncle(TreeNode<Key> *node);

        size_type size() const
        {
            return size_;
        }

        bool empty() const
        {
            return (size() == 0) ? true : false;
        }

        size_type max_size() const
        {
            return std::numeric_limits<difference_type>::max() /
                   sizeof(TreeNode<Key>);
        }

        // void Sort(TreeNode<Key> *tmp);

        void Assign(iterator *iter, Key value);

        std::pair<RedBlackTree<Key>::iterator, bool> InsertRecursive(TreeNode<Key> *parent, TreeNode<Key> *child);
        std::pair<RedBlackTree<Key>::iterator, bool> InsertNode(Key key);
        void InsCase1(TreeNode<Key> *node);
        void InsCase2(TreeNode<Key> *node);
        void InsCase3(TreeNode<Key> *node);
        void InsCase4(TreeNode<Key> *node);
        void InsCase5(TreeNode<Key> *node);

        void Remove(Key key);
        void DelCase1(TreeNode<Key> *node);
        void DelCase2(TreeNode<Key> *node);
        void DelCase3(TreeNode<Key> *node);
        void DelCase4(TreeNode<Key> *node);
        void DelCase5(TreeNode<Key> *node);
        void DelCase6(TreeNode<Key> *node);

        // probably just friend functions
        TreeNode<Key> *HandleTwoChildren(TreeNode<Key> *tmp);
        void HandleChildFree(TreeNode<Key> *tmp);
        void HanldeIfChild(TreeNode<Key> *tmp, TreeNode<Key> *child);
        TreeNode<Key> *Sibling(TreeNode<Key> *node);

        // Walkfer functions
        TreeNode<Key> *GetMin(TreeNode<Key> *tmp) const;
        TreeNode<Key> *GetMax(TreeNode<Key> *tmp) const;
        TreeNode<Key> *Next(TreeNode<Key> *tmp);
        TreeNode<Key> *Previous(TreeNode<Key> *tmp);

        void Clear();
        void LRNdelete(TreeNode<Key> *tmp);

        ~RedBlackTree();

        iterator begin();
        iterator end();
        ConstIterator cbegin() const;
        ConstIterator cend() const;

        void SetComparisonFunctions(bool (*lessFn)(const Key &v1, const Key &v2), bool (*equalFn)(const Key &v1, const Key &v2))
        {
            Less = lessFn;
            Equal = equalFn;
        }

        void
        PrintTree(TreeNode<Key> *root)
        {
            if (root == nullptr)
            {
                return;
            }

            std::queue<TreeNode<Key> *> q;
            q.push(root);

            while (!q.empty())
            {
                int nodeCount = q.size();

                while (nodeCount > 0)
                {
                    TreeNode<Key> *node = q.front();
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
                        std::cout << node->key;  // Вывод значения узла
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
    };
}
#include "tree_operations.h"
#include "insert.h"
#include "remove.h"
#include "tree_walker.h"
#include "destructor.h"
#include "iterator.h"

#endif