#ifndef CPP2_S21_CONTAINERS_1_ASSOCIATIVE_RED_BLACK_TREE_INSERT_H
#define CPP2_S21_CONTAINERS_1_ASSOCIATIVE_RED_BLACK_TREE_INSERT_H

namespace s21
{

    template <typename Key>
    void RBTree<Key>::Assign(iterator *iter, Key value)
    {
        if (iter->node != nullptr)
        {
            iter->node = value;
        }
    }

    template <typename Key>
    std::pair<typename RBTree<Key>::iterator, bool> RBTree<Key>::InsertRecursive(Node<Key> *parent, Node<Key> *child)
    {
        Node<Key> **tmp = (Less(*(child->key), *(parent->key))) ? &parent->left : &parent->right;
        std::pair<iterator, bool> result{End(), false};

        if (Equal(*(parent->key), *(child->key)))
        {

            result = std::pair<iterator, bool>{RBTree<Key>::iterator(parent, this), false};
        }
        else if (*tmp == nullptr)
        {

            *tmp = child;
            child->parent = parent;
            InsCase1(child);
            size_++;
            result = std::pair<iterator, bool>{RBTree<Key>::iterator(child, this), true};
        }
        else
        {

            result = InsertRecursive(*tmp, child);
        }
        return result;
    }

    template <typename Key>
    std::pair<typename RBTree<Key>::iterator, bool> RBTree<Key>::Insert(const Key key)
    {

        Node<Key> *new_node = new Node<Key>{new Key{key}, nullptr, nullptr, nullptr, red_node};
        std::pair<iterator, bool> result{End(), false};

        if (root == nullptr)
        {
            root = new_node;
            root->color = black_node;
            size_++;
            result = std::pair<iterator, bool>{RBTree<Key>::iterator(root, this), true};
        }
        else
        {
            result = InsertRecursive(root, new_node);
        }
        if (!result.second)
        {

            delete new_node;
        }
        return result;
    }

    template <typename Key>
    void RBTree<Key>::InsCase1(Node<Key> *node)
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

    template <typename Key>
    void RBTree<Key>::InsCase2(Node<Key> *node)
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

    template <typename Key>
    void RBTree<Key>::InsCase3(Node<Key> *node)
    {
        Node<Key> *uncle = GetUncle(node);
        if (uncle != nullptr && uncle->color == red_node)
        {
            node->parent->color = black_node;
            uncle->color = black_node;
            Node<Key> *grandpa = GetGrandpa(node);
            grandpa->color = red_node;
            InsCase1(grandpa);
        }
        else
        {
            InsCase4(node);
        }
    }

    template <typename Key>
    void RBTree<Key>::InsCase4(Node<Key> *node)
    {
        Node<Key> *grandpa = GetGrandpa(node);
        Node<Key> *tmp = node;
        Node<Key> *parent = node->parent;

        if (node == parent->right && parent == grandpa->left)
        {
            RotateLeft(parent);
            tmp = node->left;
        }
        else if (node == parent->left && parent == grandpa->right)
        {
            RotateRight(parent);
            tmp = node->right;
        }

        InsCase5(tmp);
    }

    template <typename Key>
    void RBTree<Key>::InsCase5(Node<Key> *node)
    {
        Node<Key> *grandpa = GetGrandpa(node);
        Node<Key> *parent = node->parent;
        parent->color = black_node;
        grandpa->color = red_node;

        if (node == parent->left)
        {
            RotateRight(grandpa);
        }
        else
        {
            RotateLeft(grandpa);
        }
    }
}

#endif