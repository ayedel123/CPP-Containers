#ifndef __RED_BLACK_TREE_OPERATIONS
#define __RED_BLACK_TREE_OPERATIONS

namespace s21
{

    template <typename Key>
    typename RedBlackTree<Key>::iterator RedBlackTree<Key>::Find(const Key &key)
    {
        TreeNode<Key> *tmp = RecursiveSearch(root, key);

        return (tmp)
                   ? RedBlackTree<Key>::iterator(tmp, this)
                   : end();
    }

    template <typename Key>
    TreeNode<Key> *RedBlackTree<Key>::RecursiveSearch(TreeNode<Key> *parent, Key key)
    {
        TreeNode<Key> *result = nullptr;
        if (parent == nullptr || Equal(parent->key, key))
        {
            result = parent;
        }
        else
        {
            result = (Less(key, parent->key)) ? RecursiveSearch(parent->left, key) : RecursiveSearch(parent->right, key);
        }

        return result;
    }

    template <typename Key>
    void RedBlackTree<Key>::RotateLeft(TreeNode<Key> *node)
    {
        TreeNode<Key> *right = node->right;

        right->parent = node->parent;
        if (node->parent)
        {
            TreeNode<Key> *p = node->parent;

            if (p->left == node)
            {
                p->left = right;
            }
            else
            {
                p->right = right;
            }
        }
        else
        {
            root = right;
        }

        node->right = right->left;
        if (right->left)
        {
            right->left->parent = node;
        }

        node->parent = right;
        right->left = node;
    }
    template <typename Key>
    void RedBlackTree<Key>::RotateRight(TreeNode<Key> *node)
    {
        TreeNode<Key> *left = node->left;

        left->parent = node->parent;
        if (node->parent)
        {
            TreeNode<Key> *p = node->parent;

            if (p->left == node)
            {
                p->left = left;
            }
            else
            {
                p->right = left;
            }
        }
        else
        {
            root = left;
        }

        node->left = left->right;
        if (left->right)
        {
            left->right->parent = node;
        }

        node->parent = left;
        left->right = node;
    }
    template <typename Key>
    TreeNode<Key> *RedBlackTree<Key>::GetGrandpa(TreeNode<Key> *node)
    {
        TreeNode<Key> *p = node->parent;
        if (p != nullptr && p->parent != nullptr)
        {
            return p->parent;
        }
        else
        {
            return nullptr;
        }
    }
    template <typename Key>
    TreeNode<Key> *RedBlackTree<Key>::GetUncle(TreeNode<Key> *node)
    {
        TreeNode<Key> *tmp = GetGrandpa(node);

        if (tmp != nullptr)
        {
            if (tmp->left == node->parent)
            {
                return tmp->right;
            }
            else
            {
                return tmp->left;
            }
        }
        else
        {
            return nullptr;
        }
    }

    template <typename Key>
    RedBlackTree<Key>::RedBlackTree(const RedBlackTree &other)
    {
        for (auto it = other.cbegin(); it != other.cend(); ++it)
        {
            InsertNode(*it);
        }
    }

    template <typename Key>
    RedBlackTree<Key> &RedBlackTree<Key>::operator=(const RedBlackTree &other)
    {
        if (this != &other)
        {
            Clear();
            for (auto it = other.cbegin(); it != other.cend(); ++it)
            {
                InsertNode(*it);
            }
        }
        return *this;
    }

    template <typename Key>
    RedBlackTree<Key> &RedBlackTree<Key>::operator=(RedBlackTree &&other)
    {
        if (this != &other)
        {
            Clear();
            root = other.root;
            size_ = other.size_;
            other.size_ = 0;
        }
        return *this;
    }

    template <typename Key>
    RedBlackTree<Key>::RedBlackTree(RedBlackTree<Key> &&other) noexcept
    {
        Clear();
        root = other.root;
        size_ = other.size_;
        other.root = nullptr;
        other.size_ = 0;
    }

    template <typename Key>
    void RedBlackTree<Key>::swap(RedBlackTree<Key> &first, RedBlackTree<Key> &second) noexcept
    {
        using std::swap;
        swap(first.root, second.root);
        swap(first.size_, second.size_);
    }

}

#endif