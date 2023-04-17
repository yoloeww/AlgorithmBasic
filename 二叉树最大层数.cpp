#include<algorithm>
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(root == nullptr)
            return 0;
        int res = process(root);
        return res;
    }
    int process(TreeNode* root) {
        unordered_map<TreeNode*,int> levelmap;
        levelmap.insert(pair<TreeNode*,int>(root,1));
        int curlevel = 1; // 当前在哪一层
        int curlevelnode = 0; // 当前层的宽度
        queue<TreeNode*> q;
        int maxx = 0;
        q.push(root);
        while (q.size()) {
            auto temp = q.front();
            q.pop();
            int curnodelevel = levelmap[temp];
            if (temp -> left) {
                levelmap.insert(pair<TreeNode*,int>(temp -> left, curnodelevel + 1));
                q.push(temp -> left);
            }
            if (temp -> right) {
                levelmap.insert(pair<TreeNode*,int>(temp -> right,curnodelevel + 1));
                q.push(temp -> right);
            }
            if (curnodelevel == curlevel) {
                curlevelnode ++;
            }
            else {
                maxx = max(maxx,curlevelnode);
                curlevel++;
                curlevelnode = 1;
            }
        }
        maxx = max(maxx,curlevelnode); // 最后一层
        return maxx; 
    }
};
