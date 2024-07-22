#ifndef __RED_BLACK_TREE_INSERT__
#define __RED_BLACK_TREE_INSERT__

namespace s21
{

    template <typename Key>
    void RedBlackTree<Key>::InsertRecursive(TreeNode<Key> *parent, TreeNode<Key> *child)
    {
        TreeNode<Key> **tmp = (child->key < parent->key) ? &parent->left : &parent->right;

        if (*tmp == nullptr)
        {
            *tmp = child;
            child->parent = parent;
            InsCase1(child);
            size_++;
        }
        else if ((*tmp)->key != child->key)
        {
            InsertRecursive(*tmp, child);
        }
    }

    template <typename Key>
    void RedBlackTree<Key>::InsertNode(Key key)
    {
        TreeNode<Key> *newNode = new TreeNode<Key>{key, nullptr, nullptr, nullptr, red_node};
        // newNode->key = key;
        // newNode->key = key;

        if (root == nullptr)
        {
            root = newNode;
            root->color = black_node;
            size_++;
        }
        else
        {
            InsertRecursive(root, newNode);
        }
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