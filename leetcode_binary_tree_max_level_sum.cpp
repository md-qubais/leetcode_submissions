
class Solution {
public:
    int maxLevelSum(TreeNode* root){
        if(!root){
            return 0;
        }      
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        int curr=INT_MIN;
        int level=0;
        int sum=0;
        int ans;
        while(!q.empty()){
            TreeNode*temp=q.front();
            q.pop();
            if(temp==NULL){
                level++;
                if(sum>curr){
                    curr=sum;
                    ans=level;
                }
                if(q.size()>0){
                    q.push(NULL);
                }
            }else{
                sum+=temp->val;
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
        }
        return ans;
    }
};