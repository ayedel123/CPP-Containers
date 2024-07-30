#ifndef __RED_BLACK_TREE_INSERT__
#define __RED_BLACK_TREE_INSERT__

namespace s21
{

    template <typename Key>
    void RedBlackTree<Key>::Assign(iterator *iter, Key value)
    {
        if (iter->node != nullptr)
        {
            iter->node = value;
        }
    }

    template <typename Key>
    std::pair<typename RedBlackTree<Key>::iterator, bool> RedBlackTree<Key>::InsertRecursive(TreeNode<Key> *parent, TreeNode<Key> *child)
    {
        TreeNode<Key> **tmp = (Less(child->key, parent->key)) ? &parent->left : &parent->right;
        std::pair<iterator, bool> result{RedBlackTree<Key>::iterator(this), false};
        if (Equal(parent->key, child->key))
        {
            result = std::pair<iterator, bool>{RedBlackTree<Key>::iterator(parent, this), false};
        }
        else if (*tmp == nullptr)
        {
            *tmp = child;
            child->parent = parent;
            InsCase1(child);
            size_++;
            result = std::pair<iterator, bool>{RedBlackTree<Key>::iterator(child, this), true};
        }
        else if (!Equal((*tmp)->key, child->key))
        {
            result = InsertRecursive(*tmp, child);
        }
        return result;
    }

    template <typename Key>
    std::pair<typename RedBlackTree<Key>::iterator, bool> RedBlackTree<Key>::InsertNode(const Key key)
    {

        TreeNode<Key> *newNode = new TreeNode<Key>{key, nullptr, nullptr, nullptr, red_node};
        std::pair<iterator, bool> result{RedBlackTree<Key>::iterator(this), false};

        if (root == nullptr)
        {
            root = newNode;
            root->color = black_node;
            size_++;
            result = std::pair<iterator, bool>{RedBlackTree<Key>::iterator(root, this), true};
        }
        else
        {
            result = InsertRecursive(root, newNode);
        }
        if (!result.second)
        {
            delete (newNode);
        }
        return result;
    }

    template <typename Key>
    void RedBlackTree<Key>::InsCase1(TreeNode<Key> *node)
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
    void RedBlackTree<Key>::InsCase2(TreeNode<Key> *node)
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
    void RedBlackTree<Key>::InsCase3(TreeNode<Key> *node)
    {
        TreeNode<Key> *u = GetUncle(node);
        if (u != nullptr && u->color == red_node)
        {
            node->parent->color = black_node;
            u->color = black_node;
            TreeNode<Key> *g = GetGrandpa(node);
            g->color = red_node;
            InsCase1(g);
        }
        else
        {
            InsCase4(node);
        }
    }

    template <typename Key>
    void RedBlackTree<Key>::InsCase4(TreeNode<Key> *node)
    {
        TreeNode<Key> *g = GetGrandpa(node);
        TreeNode<Key> *tmp = node;
        TreeNode<Key> *p = node->parent;

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
    void RedBlackTree<Key>::InsCase5(TreeNode<Key> *node)
    {
        TreeNode<Key> *g = GetGrandpa(node);
        TreeNode<Key> *p = node->parent;
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