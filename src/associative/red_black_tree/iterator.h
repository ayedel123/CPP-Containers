#ifndef CPP2_S21_CONTAINERS_1_ASSOCIATIVE_RED_BLACK_TREE_ITERATOR_H
#define CPP2_S21_CONTAINERS_1_ASSOCIATIVE_RED_BLACK_TREE_ITERATOR_H

namespace s21
{

    template <typename Key>
    class RBTree<Key>::Iterator
    {
        friend class RBTree;

    private:
        RBTree<Key> *parent_;
        Node<Key> *node_;

    public:
        // Iterator(RBTree<Key> *parent)
        // {
        //     node_ = nullptr;
        //     parent_ = parent;
        // }

        Iterator(Node<Key> *node, RBTree<Key> *parent)
        {
            node_ = node;
            parent_ = parent;
        }

        Iterator operator++()
        {
            if (!node_)
                return Iterator(nullptr, parent_);
            Node<Key> *result = nullptr;

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
                return Iterator(nullptr, parent_);
            Node<Key> *result = nullptr;

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

        bool operator==(const Iterator &other) const
        {
            return (node_ == other.node_) ? true : (!node_ || !other.node_) ? false
                                                                            : (node_->key == other.node_->key);
        }
        bool operator!=(const Iterator &other) const
        {
            return !(*this == other);
        }

        reference operator*()
        {
            return *(node_->key);
        }

        pointer operator->() const
        {
            return &(*(node_->key));
        }

    public:
        Node<Key> GetNode()
        {
            return *node_;
        }
    };

    template <typename Key>
    class RBTree<Key>::ConstIterator : public Iterator
    {
        friend class RBTree;
        friend class Iterator;
        using Iterator::node_;
        using Iterator::parent_;

    public:
        using Iterator::Iterator;

        ConstIterator(Node<Key> *node, RBTree<Key> *parent)
            : Iterator(node, parent) {}

        bool operator==(const ConstIterator &other) const
        {
            return Iterator::operator==(static_cast<const Iterator &>(other));
        }

        bool operator!=(const ConstIterator &other) const
        {
            return Iterator::operator!=(static_cast<const Iterator &>(other));
        }

        ConstIterator &operator++()
        {
            Iterator::operator++();
            return *this;
        }

        ConstIterator &operator--()
        {
            Iterator::operator--();
            return *this;
        }

        const_reference operator*() const
        {
            return *(node_->key);
        }

        const pointer operator->() const { return node_->key; }
    };

    template <typename Key>
    typename RBTree<Key>::Iterator RBTree<Key>::Begin()
    {
        return typename RBTree<Key>::Iterator(GetMin(root), this);
    }

    template <typename Key>
    typename RBTree<Key>::Iterator RBTree<Key>::End()
    {
        return typename RBTree<Key>::Iterator(nullptr, this);
    }

    template <typename Key>
    typename RBTree<Key>::ConstIterator RBTree<Key>::cBegin() const
    {
        return typename RBTree<Key>::ConstIterator(GetMin(root), const_cast<RBTree<Key> *>(this));
    }

    template <typename Key>
    typename RBTree<Key>::ConstIterator RBTree<Key>::cEnd() const
    {
        return typename RBTree<Key>::ConstIterator(nullptr, const_cast<RBTree<Key> *>(this));
    }
}

#endif