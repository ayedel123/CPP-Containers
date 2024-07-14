#include <iostream>
#include <queue>

enum NodeColors
{

    black_node,
    red_node
};

class TreeNode
{

public:
    int value = 0;
    TreeNode *left = nullptr;
    TreeNode *right = nullptr;
    TreeNode *parent = nullptr;
    bool color = black_node;

    TreeNode(int value)
    {
        this->value = value;
        this->color = red_node;
        parent = nullptr;
    }
};

class RedBlackTree
{
public:
    TreeNode *root = nullptr;

    void InsertRecursive(TreeNode *parent, TreeNode *child);
    void InsertNode(int value);

    TreeNode *RecursiveSearch(TreeNode *parent, int value);

    void DeleteElement(int value);

    void RotateLeft(TreeNode *node);
    void RotateRight(TreeNode *node);

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
                    if (node->color == 1)
                    {
                        // Устанавливаем красный цвет для текста
                        std::cout << "\033[1;31m"; // ASCII-код для установки цвета текста в красный
                    }
                    else
                    {
                        // Устанавливаем черный цвет для текста
                        std::cout << "\033[1;30m"; // ASCII-код для установки цвета текста в черный
                    }
                    std::cout << node->value; // Вывод значения узла
                    std::cout << "\033[0m ";  // Сброс цвета обратно в стандартный
                    if (node->left)
                    {
                        q.push(node->left);
                    }
                    if (node->right)
                    {
                        q.push(node->right);
                    }
                }
                nodeCount--;
            }
            std::cout << std::endl;
        }
    }

    TreeNode *GetGrandpa(TreeNode *node);
    TreeNode *GetUncle(TreeNode *node);

    void InsCase1(TreeNode *node);
    void InsCase2(TreeNode *node);
    void InsCase3(TreeNode *node);
    void InsCase4(TreeNode *node);
    void InsCase5(TreeNode *node);

    void Remove(int value);
    void DelCase1(TreeNode *node);
    void DelCase2(TreeNode *node);
    void DelCase3(TreeNode *node);
    void DelCase4(TreeNode *node);
    void DelCase5(TreeNode *node);
    void DelCase6(TreeNode *node);

    // probably just friend functions
    TreeNode *HandleTwoChildren(TreeNode *tmp);
    void HandleChildFree(TreeNode *tmp);
    void HanldeIfChild(TreeNode *tmp, TreeNode *child);
    TreeNode *Sibling(TreeNode *node);
};
