#include <vector>
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param root TreeNode类
     * @return int整型vector
     */
    vector<int> res;
    vector<int> preorderTraversal(TreeNode* root) {
        // write code here
        pre(root);
        return res;
    }
    void pre(TreeNode* root) {
        if (root == nullptr)
            return ;
        res.push_back(root -> val);
        pre(root -> left);
        pre(root -> right);
    }
};
