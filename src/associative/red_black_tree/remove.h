#ifndef __RED_BLACK_TREE_REMOVE__
#define __RED_BLACK_TREE_REMOVE__

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
            Node<Key> *child = (!tmp->left) ? tmp->left : tmp->right;
            if (!child)
            {
                HandleChildFree(tmp);
                // delete tmp;
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
        // f***k const

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
        Node<Key> *p = tmp->parent;

        if (p->left == tmp)
        {
            p->left = nullptr;
        }
        else
        {
            p->right = nullptr;
        }
    }
    template <typename Key>
    void RBTree<Key>::HanldeIfChild(Node<Key> *tmp, Node<Key> *child)
    {
        child->parent = tmp->parent;
        Node<Key> *p = tmp->parent;

        if (tmp->parent)
        {
            if (tmp == p->left)
            {
                // DeleteNode(p->left);
                p->left = child;
            }
            else
            {
                // DeleteNode(p->right);
                p->right = child;
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
        Node<Key> *s = Sibling(node);
        Node<Key> *p = node->parent;
        bool scol = s ? s->color : black_node;

        if (scol == red_node)
        {
            p->color = red_node;
            s->color = black_node;

            if (node == p->left)
            {
                RotateLeft(p);
            }
            else
            {
                RotateRight(p);
            }
        }

        DelCase3(node);
    }
    template <typename Key>
    void RBTree<Key>::DelCase3(Node<Key> *node)
    {
        Node<Key> *s = Sibling(node);
        Node<Key> *p = node->parent;

        bool scol = s ? s->color : black_node;
        bool lcol = s && s->left ? s->left->color : black_node;
        bool rcol = s && s->right ? s->right->color : black_node;

        if (p->color == black_node && scol == black_node && lcol == black_node && rcol == black_node)
        {
            if (s)
            {
                s->color = red_node;
            }
            DelCase1(p);
        }
        else
        {
            DelCase4(node);
        }
    }
    template <typename Key>
    void RBTree<Key>::DelCase4(Node<Key> *node)
    {
        Node<Key> *s = Sibling(node);
        Node<Key> *p = node->parent;

        bool scol = s ? s->color : black_node;
        bool lcol = s && s->left ? s->left->color : black_node;
        bool rcol = s && s->right ? s->right->color : black_node;

        if (p->color == red_node && scol == black_node && lcol == black_node && rcol == black_node)
        {
            if (s)
            {
                s->color = red_node;
            }
            p->color = black_node;
        }
        else
        {
            DelCase5(node);
        }
    }
    template <typename Key>
    void RBTree<Key>::DelCase5(Node<Key> *node)
    {
        Node<Key> *s = Sibling(node);
        Node<Key> *p = node->parent;

        bool lcol = s->left ? s->left->color : black_node;
        bool rcol = s->right ? s->right->color : black_node;

        if (s->color == black_node)
        {
            if (node == p->left && rcol == black_node && lcol == red_node)
            {
                s->color = red_node;
                s->left->color = black_node;
                RotateRight(s);
            }
            else if (node == p->right && lcol == black_node && rcol == red_node)
            {
                s->color = red_node;
                s->right->color = black_node;
                RotateLeft(s);
            }
        }

        DelCase6(node);
    }
    template <typename Key>
    void RBTree<Key>::DelCase6(Node<Key> *node)
    {
        Node<Key> *s = Sibling(node);
        Node<Key> *p = node->parent;
        s->color = p->color;
        p->color = black_node;

        if (node == p->left)
        {
            if (s->right)
            {
                s->right->color = black_node;
            }
            RotateLeft(p);
        }
        else
        {
            if (s->left)
            {
                s->left->color = black_node;
            }
            RotateRight(p);
        }
    }
}

#endif