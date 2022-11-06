#include <bits/stdc++.h>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void inorder(TreeNode *root, double target, int &ans)
{
    if(!root)
        return;

    inorder(root->left, target, ans);
    if(root->val > target)
    {
        if(ans >= target)
            return;
            
        ans = (root->val - target < target - ans)? root->val : ans;
        return;
    }
    else
        ans = root->val;
    inorder(root->right, target, ans);
}

int closestValue(TreeNode *root, double target)
{
    int ans;
    TreeNode *tmp = root;
    while(tmp->left)
        tmp = tmp->left;
    ans = tmp->val;
    inorder(root, target, ans);

    return ans;
}

int main()
{
    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    double target = 2.714286;
    int ans = closestValue(root, target);

    cout << ans << endl;

    return 0;
}