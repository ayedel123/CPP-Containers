#ifndef __RED_BLACK_TREE_INSERT__
#define __RED_BLACK_TREE_INSERT__

namespace s21
{

    template <typename Key, typename T>
    void RedBlackTree<Key, T>::InsertRecursive(TreeNode<Key, T> *parent, TreeNode<Key, T> *child)
    {
        TreeNode<Key, T> **tmp = (child->key < parent->key) ? &parent->left : &parent->right;

        if (*tmp == nullptr)
        {
            *tmp = child;
            child->parent = parent;
            InsCase1(child);
            size_++;
        }
        else if ((*tmp)->key != child->key)
        {
            InsertRecursive(*tmp, child);
        }
    }

    template <typename Key, typename T>
    void RedBlackTree<Key, T>::InsertNode(Key key, T value)
    {
        TreeNode<Key, T> *newNode = new TreeNode<Key, T>{key, value, nullptr, nullptr, nullptr, red_node};
        // newNode->key = key;
        // newNode->key = key;

        if (root == nullptr)
        {
            root = newNode;
            root->color = black_node;
            size_++;
        }
        else
        {
            InsertRecursive(root, newNode);
        }
    }

    template <typename Key, typename T>
    void RedBlackTree<Key, T>::InsCase1(TreeNode<Key, T> *node)
    {
        if (node->parent == nullptr)
        {
            node->color = black_node;
        }
        else
        {
            InsCase2(node);
        }
    }

    template <typename Key, typename T>
    void RedBlackTree<Key, T>::InsCase2(TreeNode<Key, T> *node)
    {
        if (node->parent->color == black_node)
        {
            return;
        }
        else
        {
            InsCase3(node);
        }
    }

    template <typename Key, typename T>
    void RedBlackTree<Key, T>::InsCase3(TreeNode<Key, T> *node)
    {
        TreeNode<Key, T> *u = GetUncle(node);
        if (u != nullptr && u->color == red_node)
        {
            node->parent->color = black_node;
            u->color = black_node;
            TreeNode<Key, T> *g = GetGrandpa(node);
            g->color = red_node;
            InsCase1(g);
        }
        else
        {
            InsCase4(node);
        }
    }

    template <typename Key, typename T>
    void RedBlackTree<Key, T>::InsCase4(TreeNode<Key, T> *node)
    {
        TreeNode<Key, T> *g = GetGrandpa(node);
        TreeNode<Key, T> *tmp = node;
        TreeNode<Key, T> *p = node->parent;

        if (node == p->right && p == g->left)
        {
            RotateLeft(p);
            tmp = node->left;
        }
        else if (node == p->left && p == g->right)
        {
            RotateRight(p);
            tmp = node->right;
        }

        InsCase5(tmp);
    }

    template <typename Key, typename T>
    void RedBlackTree<Key, T>::InsCase5(TreeNode<Key, T> *node)
    {
        TreeNode<Key, T> *g = GetGrandpa(node);
        TreeNode<Key, T> *p = node->parent;
        p->color = black_node;
        g->color = red_node;

        if (node == p->left)
        {
            RotateRight(g);
        }
        else
        {
            RotateLeft(g);
        }
    }
}

#endif