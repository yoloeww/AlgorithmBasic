class ReturnType {
public:
    int maxDistance;
    int height;
    ReturnType(int maxDistance,int height) : 
        maxDistance(maxDistance),height(height) {
    }
};

ReturnType process(TreeNode* head) {

    if (head == 0)
        return ReturnType(0, 0);
    ReturnType leftData = process(head->left);
    ReturnType rightData = process(head->right);

    int height = max(leftData.height,rightData.height);

    int maxDistance = max(leftData.height + rightData.height + 1,max(rightData.maxDistance,leftData.maxDistance));
    return ReturnType(maxDistance, height);
}
int getMaxDistance(TreeNode* head) {
    return process(head).maxDistance;
}
