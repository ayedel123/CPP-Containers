#ifndef __RED_BLACK_TREE_ITERATOR__
#define __RED_BLACK_TREE_ITERATOR__

namespace s21
{

    template <typename Key>
    class RedBlackTree<Key>::iterator
    {
    private:
        RedBlackTree<Key> *parent_;
        TreeNode<Key> *node_;

    public:
        iterator(RedBlackTree<Key> *parent)
        {
            node_ = nullptr;
            parent_ = parent;
        }

        iterator(TreeNode<Key> *node, RedBlackTree<Key> *parent)
        {
            node_ = node;
            parent_ = parent;
        }

        iterator operator++()
        {
            if (!node_)
                return nullptr;
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

        iterator operator--()
        {
            if (!node_)
                return nullptr;
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

        bool operator==(const iterator &other) const
        {
            return (node_ == other->node_);
        }
        bool operator!=(const iterator &other) const
        {
            return (node_ == other->node_);
        }

        Key operator*()
        {
            return node_->key;
        }
    };

    template <typename Key>
    typename RedBlackTree<Key>::iterator RedBlackTree<Key>::begin()
    {
        return typename RedBlackTree<Key>::iterator(GetMin(root), this);
    }

    template <typename Key>
    typename RedBlackTree<Key>::iterator RedBlackTree<Key>::end()
    {
        return typename RedBlackTree<Key>::iterator(this);
    }
}

#endif