/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
struct info{
    bool isB;
    int height;
    info(bool isB,int height) : isB(isB),height(height)
    {}
};
    bool isBalanced(TreeNode* root) {
        if(root == nullptr)
            return true;
        return process2(root).isB;
    }
    info process2(TreeNode* x) {
        if (x == nullptr) {
            info res = info(true,0);
            return res;
        }
        info leftinfo = process2(x -> left);
        info rightinfo = process2(x -> right);
        bool isB = true;
        int height = max(leftinfo.height,rightinfo.height) + 1;
        if (!leftinfo.isB  || !rightinfo.isB ||
        abs(leftinfo.height - rightinfo.height) > 1)
            isB =  false;
        info res = info(isB,height);
        return res;
    }
};
