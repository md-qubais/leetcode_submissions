
class Solution {
public:
    vector<int> ans;
    vector<int> postorder(Node* root) {
        if(root==NULL){
            vector<int> res;
            return res;
        }
        for(auto it:root->children){
            postorder(it);
        }
        ans.push_back(root->val);
        return ans;
    }
};