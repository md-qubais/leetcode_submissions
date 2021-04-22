int ans=0;
class Pair{
public:
    int sum;
    bool isbst;
    int maxLeft;
    int minRight;
    Pair(){
        sum=0;
        isbst=true;
        maxLeft=INT_MIN;
        minRight=INT_MAX;
    }
};
class Solution{
public:
    Pair max_sum(TreeNode*root){
        Pair p;
        if(!root){
            return p;
        }
        Pair left=max_sum(root->left);
        Pair right=max_sum(root->right);


        if(left.isbst and right.isbst){
            if(left.maxLeft<root->val and root->val<right.minRight){
                p.sum+=left.sum+right.sum+root->val;
                ans=max(p.sum,ans);
                p.maxLeft=max(root->val,right.maxLeft);
                p.minRight=min(root->val,left.minRight);
                p.isbst=true;
                return p;
            }
        }
        p=left.sum>right.sum?left:right;
        p.isbst=false;
        return p;
    }
    int maxSumBST(TreeNode* root){
        if(!root) return 0;
        max_sum(root);
        int answer=ans;
        ans=0;
        return answer;
    }
};