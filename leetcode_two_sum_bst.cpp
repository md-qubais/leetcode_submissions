class Solution {
public:
    vector<int> arr;
    void inorder(TreeNode*root){
        if(!root) return;
        inorder(root->left);
        arr.push_back(root->val);
        inorder(root->right);
    }
    bool findTarget(TreeNode* root, int k){
        inorder(root);
        int s=0;
        int e=arr.size()-1;
        while(s<e){
            if(arr[s]+arr[e]==k){
                return true;
            }
            if(arr[s]+arr[e]>k){
                e--;
            }else{
                s++;
            }
        }
        return false;
    }
};