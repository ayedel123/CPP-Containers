#ifndef __RED_BLACK_TREE_INSERT__
#define __RED_BLACK_TREE_INSERT__

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
        std::pair<iterator, bool> result{end(), false};

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
    std::pair<typename RBTree<Key>::iterator, bool> RBTree<Key>::InsertNode(const Key key)
    {

        Node<Key> *newNode = new Node<Key>{new Key{key}, nullptr, nullptr, nullptr, red_node};
        std::pair<iterator, bool> result{end(), false};

        if (root == nullptr)
        {
            root = newNode;
            root->color = black_node;
            size_++;
            result = std::pair<iterator, bool>{RBTree<Key>::iterator(root, this), true};
        }
        else
        {
            result = InsertRecursive(root, newNode);
        }
        if (!result.second)
        {

            DeleteNode(newNode);
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
        Node<Key> *u = GetUncle(node);
        if (u != nullptr && u->color == red_node)
        {
            node->parent->color = black_node;
            u->color = black_node;
            Node<Key> *g = GetGrandpa(node);
            g->color = red_node;
            InsCase1(g);
        }
        else
        {
            InsCase4(node);
        }
    }

    template <typename Key>
    void RBTree<Key>::InsCase4(Node<Key> *node)
    {
        Node<Key> *g = GetGrandpa(node);
        Node<Key> *tmp = node;
        Node<Key> *p = node->parent;

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

    template <typename Key>
    void RBTree<Key>::InsCase5(Node<Key> *node)
    {
        Node<Key> *g = GetGrandpa(node);
        Node<Key> *p = node->parent;
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