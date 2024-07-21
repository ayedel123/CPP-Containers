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
        red_node
    };

    template <typename Key, typename T>
    struct TreeNode
    {
        Key key;
        T value;
        TreeNode<Key, T> *left = nullptr;
        TreeNode<Key, T> *right = nullptr;
        TreeNode<Key, T> *parent = nullptr;
        bool color = black_node;
    };

    template <typename Key, typename T>
    class RedBlackTree
    {

    public:
        using size_type = size_t;
        using difference_type = std::ptrdiff_t;

    private:
        size_type size_ = 0;

    public:
        TreeNode<Key, T> *root = nullptr;

        TreeNode<Key, T> *RecursiveSearch(TreeNode<Key, T> *parent, Key key);

        void RotateLeft(TreeNode<Key, T> *node);
        void RotateRight(TreeNode<Key, T> *node);
        void SwapColors();

        TreeNode<Key, T> *GetGrandpa(TreeNode<Key, T> *node);
        TreeNode<Key, T> *GetUncle(TreeNode<Key, T> *node);

        size_type size()
        {
            return size_;
        }

        bool empty()
        {
            return (size_ == 0) ? true : false;
        }

        size_type max_size()
        {
            return std::numeric_limits<difference_type>::max() /
                   sizeof(TreeNode<Key, T>);
        }

        //void Sort(TreeNode<Key, T> *tmp);

        void InsertRecursive(TreeNode<Key, T> *parent, TreeNode<Key, T> *child);
        void InsertNode(Key key, T value);
        void InsCase1(TreeNode<Key, T> *node);
        void InsCase2(TreeNode<Key, T> *node);
        void InsCase3(TreeNode<Key, T> *node);
        void InsCase4(TreeNode<Key, T> *node);
        void InsCase5(TreeNode<Key, T> *node);

        void Remove(Key key);
        void DelCase1(TreeNode<Key, T> *node);
        void DelCase2(TreeNode<Key, T> *node);
        void DelCase3(TreeNode<Key, T> *node);
        void DelCase4(TreeNode<Key, T> *node);
        void DelCase5(TreeNode<Key, T> *node);
        void DelCase6(TreeNode<Key, T> *node);

        // probably just friend functions
        TreeNode<Key, T> *HandleTwoChildren(TreeNode<Key, T> *tmp);
        void HandleChildFree(TreeNode<Key, T> *tmp);
        void HanldeIfChild(TreeNode<Key, T> *tmp, TreeNode<Key, T> *child);
        TreeNode<Key, T> *Sibling(TreeNode<Key, T> *node);

        // Walkfer functions
        TreeNode<Key, T> *GetMin(TreeNode<Key, T> *tmp);
        TreeNode<Key, T> *GetMax(TreeNode<Key, T> *tmp);
        TreeNode<Key, T> *Next(TreeNode<Key, T> *tmp);
        TreeNode<Key, T> *Previous(TreeNode<Key, T> *tmp);

        void
        PrintTree(TreeNode<Key, T> *root)
        {
            if (root == nullptr)
            {
                return;
            }

            std::queue<TreeNode<Key, T> *> q;
            q.push(root);

            while (!q.empty())
            {
                int nodeCount = q.size();

                while (nodeCount > 0)
                {
                    TreeNode<Key, T> *node = q.front();
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

#endif