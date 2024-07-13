#include <iostream>
#include <queue>

enum NodeColors
{
    red_node,
    black_node
};

class TreeNode
{

public:
    int value = 0;
    TreeNode *left_node = nullptr;
    TreeNode *right_node = nullptr;
    TreeNode *parent = nullptr;
    int color = black_node;

    TreeNode(int value)
    {
        this->value = value;
        this->color = red_node;
    }
    // TreeNode(int value, TreeNode *parent) : TreeNode(value)
    // {
    //     this->parent = parent;
    // }
};

class RedBlackTree
{
public:
    TreeNode *root = nullptr;

    void InsertRecursive(TreeNode *parent, TreeNode *child);
    void InsertNode(int value);

    TreeNode *RecursiveSearch(TreeNode *parent, int value);

    void DeleteElement(int value);

    void TurnRight(TreeNode *node);

    void TurnLeft(TreeNode *node);
    void SwapColors();

    void PrintTree(TreeNode *root)
    {
        if (root == nullptr)
        {
            return;
        }

        std::queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            int nodeCount = q.size();

            while (nodeCount > 0)
            {
                TreeNode *node = q.front();
                q.pop();
                if (node)
                {
                    std::cout << node->value << " ";
                    if (node->left_node)
                    {
                        q.push(node->left_node);
                    }
                    if (node->right_node)
                    {
                        q.push(node->right_node);
                    }
                }
                nodeCount--;
            }
            std::cout << std::endl;
        }
    }
};