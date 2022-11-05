#include <iostream>

#include <array>

using namespace std;

class TreeNode
{
    public:
        TreeNode(int x)
        {
            right = NULL;
            left = NULL;
            data = x;
        }
        int data;
        TreeNode * left;
        TreeNode * right;
};

void printPost(TreeNode* root)
{
    if (root == NULL)
        return;
 
    printPost(root->left);
    printPost(root->right);
    cout<< root->data<<" ";
}

TreeNode* buildTree(int in[],int pre[], int &start, int &end)
{
    int counter = 0;
    
    int root_in;

    if(start > end)
    {return NULL;}
    TreeNode* root_pre = new TreeNode(pre[counter++]);


    //find the root position in inorder array
    if(start == end)
    {
        return root_pre;
    }

    for(int j = start; j <= end; j++)
    {
        if(in[j] == root_pre->data)
        {
            root_in = j;
            cout << j << endl;
            break;
        }
    }
    
    root_pre->setLeft(buildTree(in, pre, start, root_in-1));
    root_pre->setRight(buildTree(in, pre, root_in+1, end));

    return root_pre;
    
}

int main()
{
    int t,n,item;
    scanf("%d",&t);
    for(int i = 0; i<t; i++)
    {
        scanf("%d",&n);
        int preOrder[n];
        int inOrder[n];
        for(int j = 0; j < n; j++)
        {
            scanf("%d",&item);
            preOrder[j] = item;
        }
        for(int j = 0; j < n; j++)
        {
            scanf("%d",&item);
            inOrder[j] = item;
        }
        TreeNode * tree = buildTree(inOrder, preOrder,0,n-1);
        printPost(tree);
        freeTree(tree);
    }

}