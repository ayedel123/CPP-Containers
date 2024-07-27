#ifndef __RED_BLACK_TREE_ITERATOR__
#define __RED_BLACK_TREE_ITERATOR__

namespace s21
{

    template <typename Key>
    class RedBlackTree<Key>::Iterator
    {
        friend class RedBlackTree;

    private:
        RedBlackTree<Key> *parent_;
        TreeNode<Key> *node_;

    public:
        Iterator(RedBlackTree<Key> *parent)
        {
            node_ = nullptr;
            parent_ = parent;
        }

        Iterator(TreeNode<Key> *node, RedBlackTree<Key> *parent)
        {
            node_ = node;
            parent_ = parent;
        }

        Iterator operator++()
        {
            if (!node_)
                return ConstIterator(parent_);
            TreeNode<Key> *result = nullptr;

            if (node_->right)
            {
                result = parent_->GetMin(node_->right);
            }
            else
            {
                result = node_->parent;
                while (result && node_ == result->right)
                {
                    node_ = result;
                    result = node_->parent;
                }
            }
            node_ = result;
            return *this;
        }

        Iterator operator--()
        {
            if (!node_)
                return ConstIterator(parent_);
            TreeNode<Key> *result = nullptr;

            if (node_->left)
            {
                result = parent_->GetMax(node_->left);
            }
            else
            {
                result = node_->parent;
                while (result && node_ == result->left)
                {
                    node_ = result;
                    result = node_->parent;
                }
            }

            node_ = result;
            return *this;
        }

        bool operator==(Iterator &other)
        {
            return (node_ == other->node_);
        }
        bool operator!=(Iterator &other)
        {
            return (node_ == other->node_);
        }

        reference operator*()
        {
            return node_->key;
        }

        pointer operator->() const { return node_->data_; }
    };

    template <typename Key>
    class RedBlackTree<Key>::ConstIterator
    {
        friend class RedBlackTree;

    private:
        RedBlackTree<Key> *parent_;
        TreeNode<Key> *node_;

    public:
        ConstIterator(RedBlackTree<Key> *parent)
        {
            node_ = nullptr;
            parent_ = parent;
        }

        ConstIterator(TreeNode<Key> *node, RedBlackTree<Key> *parent)
        {
            node_ = node;
            parent_ = parent;
        }

        ConstIterator operator++()
        {
            if (!node_)
                return ConstIterator(parent_);
            TreeNode<Key> *result = nullptr;
            TreeNode<Key> *tmp = node_;
            if (tmp->right)
            {
                result = parent_->GetMin(tmp->right);
            }
            else
            {
                result = tmp->parent;
                while (result && tmp == result->right)
                {
                    tmp = result;
                    result = tmp->parent;
                }
            }
            tmp = result;
            node_ = tmp;
            // return ConstIterator(tmp, parent_);
            return *this;
        }

        ConstIterator operator--() const
        {
            if (!node_)
                return ConstIterator(parent_);
            TreeNode<Key> *result = nullptr;
            TreeNode<Key> *tmp = node_;
            if (tmp->left)
            {
                result = parent_->GetMax(tmp->left);
            }
            else
            {
                result = tmp->parent;
                while (result && tmp == result->left)
                {
                    tmp = result;
                    result = tmp->parent;
                }
            }

            tmp = result;
            node_ = tmp;
            // return ConstIterator(tmp, parent_);
            return *this;
        }

        bool operator==(const ConstIterator &other) const
        {
            return (node_ == other.node_);
        }
        bool operator!=(const ConstIterator &other) const
        {
            return (node_ != other.node_);
        }

        const_reference operator*() const
        {
            return node_->key;
        }

        const pointer operator->() const { return node_->data_; }
    };

    template <typename Key>
    typename RedBlackTree<Key>::Iterator RedBlackTree<Key>::begin()
    {
        return typename RedBlackTree<Key>::Iterator(GetMin(root), this);
    }

    template <typename Key>
    typename RedBlackTree<Key>::Iterator RedBlackTree<Key>::end()
    {
        return typename RedBlackTree<Key>::Iterator(this);
    }

    template <typename Key>
    typename RedBlackTree<Key>::ConstIterator RedBlackTree<Key>::cbegin() const
    {
        return typename RedBlackTree<Key>::ConstIterator(GetMin(root), const_cast<RedBlackTree<Key> *>(this));
    }

    template <typename Key>
    typename RedBlackTree<Key>::ConstIterator RedBlackTree<Key>::cend() const
    {
        return typename RedBlackTree<Key>::ConstIterator(nullptr, const_cast<RedBlackTree<Key> *>(this));
    }

}

#endif