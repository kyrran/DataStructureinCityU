#include <iostream>
#include <string>
#include <queue>

using namespace std;
class TreeNode
{
    public:
        TreeNode()
        {
            right = NULL;
            left = NULL;
            parent = NULL;
            data = -1;
        }
        TreeNode * getLeft()
        {
            return left;
        }
        TreeNode * getRight()
        {
            return left;
        }
        TreeNode * getParent()
        {
            return left;
        }
        TreeNode * getData()
        {
            return data;
        }

        void setLeft(TreeNode * x)
        {
            left = x;
        }
        void setRight(TreeNode * y)
        {
            right = y;
        }
        void setParent(TreeNode * z)
        {
            parent = z;
        }
        void setData(int val)
        {
            data = val;
        }
    private:
        int data;
        TreeNode * left;
        TreeNode * right;
        TreeNode * parent;
};

class BinaryTree
{
    public:
        BinaryTree()
        {
            root = NULL;
        }

        TreeNode* getRoot()
        {
            return root;
        }

        void preOrder();
        void inOrder();
        void postOrder();
        void preOrderHelper(TreeNode * cur);
        void inOrderHelper(TreeNode * cur);
        void postOrderHelper(TreeNode * cur);
        void getHeight();
    private:
        TreeNode * root;
};

void BinaryTree::preOrder()
{
    preOrderHelper(getRoot());
}
void BinaryTree::inOrder()
{
    inOrderHelper(getRoot());
}
void BinaryTree::postOrder()
{
    postOrderHelper(getRoot());
}
void BinaryTree::preOrderHelper(TreeNode * cur)
{
    if(cur != NULL)
    {
        cout << cur->getData() << " ";
        preOrderHelper(cur->getLeft());
        preOrderHelper(cur->getRight());
    }
}
void BinaryTree::inOrderHelper(TreeNode * cur)
{
    if(cur != NULL)
    {
        preOrderHelper(cur->getLeft());
        cout << cur->getData() << " ";
        preOrderHelper(cur->getRight());
    }
}
void BinaryTree::postOrderHelper(TreeNode * cur)
{
    
    preOrderHelper(cur->getLeft());
    preOrderHelper(cur->getRight());
    cout << cur->getData() << " ";
}
void BinaryTree::getHeight();