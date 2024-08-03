#ifndef __RED_BLACK_TREE_OPERATIONS
#define __RED_BLACK_TREE_OPERATIONS

namespace s21
{

    template <typename Key>
    typename RBTree<Key>::iterator RBTree<Key>::Find(const Key &key)
    {
        Node<Key> *tmp = RecursiveSearch(root, key);

        return (tmp)
                   ? RBTree<Key>::iterator(tmp, this)
                   : end();
    }

    template <typename Key>
    Node<Key> *RBTree<Key>::RecursiveSearch(Node<Key> *parent, Key key)
    {
        Node<Key> *result = nullptr;
        if (parent == nullptr || Equal(*(parent->key), key))
        {
            result = parent;
        }
        else
        {
            result = (Less(key, *(parent->key))) ? RecursiveSearch(parent->left, key) : RecursiveSearch(parent->right, key);
        }

        return result;
    }

    template <typename Key>
    void RBTree<Key>::RotateLeft(Node<Key> *node)
    {
        Node<Key> *right = node->right;

        right->parent = node->parent;
        if (node->parent)
        {
            Node<Key> *p = node->parent;

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
    void RBTree<Key>::RotateRight(Node<Key> *node)
    {
        Node<Key> *left = node->left;

        left->parent = node->parent;
        if (node->parent)
        {
            Node<Key> *p = node->parent;

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
    Node<Key> *RBTree<Key>::GetGrandpa(Node<Key> *node)
    {
        Node<Key> *p = node->parent;
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
    Node<Key> *RBTree<Key>::GetUncle(Node<Key> *node)
    {
        Node<Key> *tmp = GetGrandpa(node);

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
    RBTree<Key>::RBTree(const RBTree &other)
    {
        for (auto it = other.cbegin(); it != other.cend(); ++it)
        {
            InsertNode(*it);
        }
    }

    template <typename Key>
    RBTree<Key> &RBTree<Key>::operator=(const RBTree &other)
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
    RBTree<Key> &RBTree<Key>::operator=(RBTree &&other)
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
    RBTree<Key>::RBTree(RBTree<Key> &&other) noexcept
    {
        Clear();
        root = other.root;
        size_ = other.size_;
        other.root = nullptr;
        other.size_ = 0;
    }

    template <typename Key>
    void RBTree<Key>::swap(RBTree<Key> &first, RBTree<Key> &second) noexcept
    {
        using std::swap;
        swap(first.root, second.root);
        swap(first.size_, second.size_);
    }

}

#endif