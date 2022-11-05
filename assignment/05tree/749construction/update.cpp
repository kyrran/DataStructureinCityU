#include <iostream>
#include <unordered_map>
#include <array>
#include <vector>
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

bool printPost(TreeNode* root)
{
    if (root == NULL)
        return false;
 
    if (printPost(root->left))
        cout << " ";
    
    if(printPost(root->right))
        cout << " ";

    return(cout<< root->data);
}

TreeNode* build(vector<int> &pre, vector<int> &in, int start, int end, unordered_map<int,int> &map, int &preIndex) 
{
    if(start > end) 
    {
        return NULL;
    }

    int Rootval = pre[preIndex++];
    TreeNode* root = new TreeNode(Rootval);
    int curRootIndex_in = map[Rootval];
    
    root->left = build(pre, in,  start, curRootIndex_in-1, map, preIndex);
    root->right = build(pre, in, curRootIndex_in+1, end, map, preIndex);
            
    return root;
}

int main()
{
    int t,n,item;
    scanf("%d",&t);
    TreeNode * arr[t];
    for(int i = 0; i<t; i++)
    {
        
        scanf("%d",&n);

        unordered_map<int,int> in_map;
        vector<int> preorder,inorder;

        for(int j = 0; j < n; j++)
        {
            scanf("%d",&item);
            preorder.push_back(item);
        }
        for(int j = 0; j < n; j++)
        {
            scanf("%d",&item);
         
            in_map[item] = j;
            inorder.push_back(item);
        }
        int preIndex = 0;
        
        TreeNode * root = build(preorder, inorder, 0, n-1, in_map, preIndex);
        arr[i] = root;
        
    }
    for(int j = 0; j < t; j++)
    {
        printPost(arr[j]);
        cout << endl;
    }
        
}