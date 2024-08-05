#ifndef CPP2_S21_CONTAINERS_1_ASSOCIATIVE_RED_BLACK_TREE_REMOVE_H
#define CPP2_S21_CONTAINERS_1_ASSOCIATIVE_RED_BLACK_TREE_REMOVE_H

namespace s21
{

    template <typename Key>
    void RBTree<Key>::Remove(Key key)
    {
        Node<Key> *tmp = (root != nullptr) ? RecursiveSearch(root, key) : nullptr;
        if (!tmp)
            return;

        size_--;
        if (!tmp->parent && !tmp->left && !tmp->right)
        {

            root = nullptr;
        }
        if (root)
        {
            if (tmp->left && tmp->right)
            {
                tmp = HandleTwoChildren(tmp);
            }
            Node<Key> *child = (tmp->left) ? tmp->left : tmp->right;
            if (!child)
            {
                HandleChildFree(tmp);
            }

            else
            {
                HanldeIfChild(tmp, child);
            }
        }
        delete tmp;
    }

    template <typename Key>
    Node<Key> *RBTree<Key>::HandleTwoChildren(Node<Key> *tmp)
    {
        Node<Key> *removed = tmp->left;
        while (removed->right)
        {
            removed = removed->right;
        }

        delete tmp->key;
        tmp->key = new Key{*(removed->key)};
        return removed;
    }

    template <typename Key>
    void RBTree<Key>::HandleChildFree(Node<Key> *tmp)
    {
        if (tmp->color == black_node)
        {
            DelCase1(tmp);
        }
        Node<Key> *parent = tmp->parent;

        if (parent->left == tmp)
        {
            parent->left = nullptr;
        }
        else
        {
            parent->right = nullptr;
        }
    }
    template <typename Key>
    void RBTree<Key>::HanldeIfChild(Node<Key> *tmp, Node<Key> *child)
    {
        child->parent = tmp->parent;
        Node<Key> *parent = tmp->parent;

        if (tmp->parent)
        {
            if (tmp == parent->left)
            {
                parent->left = child;
            }
            else
            {
                parent->right = child;
            }
        }
        else
        {
            root = child;
            if (tmp->color == black_node)
            {
                if (child->color == red_node)
                {
                    child->color = black_node;
                }
                else
                {
                    DelCase1(child);
                }
            }
        }
    }
    template <typename Key>
    Node<Key> *RBTree<Key>::Sibling(Node<Key> *node)
    {
        Node<Key> *sibling = nullptr;
        if (node && node->parent)
        {
            sibling = (node->parent->left == node) ? node->parent->right : node->parent->left;
        }
        return sibling;
    }
    template <typename Key>
    void RBTree<Key>::DelCase1(Node<Key> *node)
    {
        if (node->parent)
        {
            DelCase2(node);
        }
    }
    template <typename Key>
    void RBTree<Key>::DelCase2(Node<Key> *node)
    {
        Node<Key> *sibling = Sibling(node);
        Node<Key> *parent = node->parent;
        bool sibling_color = sibling ? sibling->color : black_node;

        if (sibling_color == red_node)
        {
            parent->color = red_node;
            sibling->color = black_node;

            if (node == parent->left)
            {
                RotateLeft(parent);
            }
            else
            {
                RotateRight(parent);
            }
        }

        DelCase3(node);
    }
    template <typename Key>
    void RBTree<Key>::DelCase3(Node<Key> *node)
    {
        Node<Key> *sibling = Sibling(node);
        Node<Key> *parent = node->parent;

        bool sibling_color = sibling ? sibling->color : black_node;
        bool lcolor = sibling && sibling->left ? sibling->left->color : black_node;
        bool rcolor = sibling && sibling->right ? sibling->right->color : black_node;

        if (parent->color == black_node && sibling_color == black_node && lcolor == black_node && rcolor == black_node)
        {
            if (sibling)
            {
                sibling->color = red_node;
            }
            DelCase1(parent);
        }
        else
        {
            DelCase4(node);
        }
    }
    template <typename Key>
    void RBTree<Key>::DelCase4(Node<Key> *node)
    {
        Node<Key> *sibling = Sibling(node);
        Node<Key> *parent = node->parent;

        bool sibling_color = sibling ? sibling->color : black_node;
        bool lcolor = sibling && sibling->left ? sibling->left->color : black_node;
        bool rcolor = sibling && sibling->right ? sibling->right->color : black_node;

        if (parent->color == red_node && sibling_color == black_node && lcolor == black_node && rcolor == black_node)
        {
            if (sibling)
            {
                sibling->color = red_node;
            }
            parent->color = black_node;
        }
        else
        {
            DelCase5(node);
        }
    }
    template <typename Key>
    void RBTree<Key>::DelCase5(Node<Key> *node)
    {
        Node<Key> *sibling = Sibling(node);
        Node<Key> *parent = node->parent;

        bool lcolor = sibling->left ? sibling->left->color : black_node;
        bool rcolor = sibling->right ? sibling->right->color : black_node;

        if (sibling->color == black_node)
        {
            if (node == parent->left && rcolor == black_node && lcolor == red_node)
            {
                sibling->color = red_node;
                sibling->left->color = black_node;
                RotateRight(sibling);
            }
            else if (node == parent->right && lcolor == black_node && rcolor == red_node)
            {
                sibling->color = red_node;
                sibling->right->color = black_node;
                RotateLeft(sibling);
            }
        }

        DelCase6(node);
    }
    template <typename Key>
    void RBTree<Key>::DelCase6(Node<Key> *node)
    {
        Node<Key> *sibling = Sibling(node);
        Node<Key> *parent = node->parent;
        sibling->color = parent->color;
        parent->color = black_node;

        if (node == parent->left)
        {
            if (sibling->right)
            {
                sibling->right->color = black_node;
            }
            RotateLeft(parent);
        }
        else
        {
            if (sibling->left)
            {
                sibling->left->color = black_node;
            }
            RotateRight(parent);
        }
    }
}

#endif