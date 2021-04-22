class Solution{
public:
    int depth(TreeNode*root){
        if(root==NULL){
            return -1;
        }
        return 1+max(depth(root->left),depth(root->right));
    }
    int minCameraCover(TreeNode* root){
        int ans=0;
        if(!root){
            return ans;
        }
        if(!root->left and !root->right){
            return 1;
        }
        int max_depth=depth(root);
        int num=0;
        for(int i=0;i<=max_depth;i++){
            num+=pow(2,i);
        }
        queue<TreeNode*> q;
        q.push(root);
        vector<int> arr;
        arr.push_back(-1);
        arr.push_back(root->val);

        while(arr.size()-1!=num){
            TreeNode*temp=q.front();
            q.pop();
            if(temp){
            if(temp->left){
                q.push(temp->left);
                arr.push_back(temp->left->val);
            }else{
                q.push(NULL);
                arr.push_back(-1);
            }
            if(temp->right){
                q.push(temp->right);
                arr.push_back(temp->right->val);
            }else{
                q.push(NULL);
                arr.push_back(-1);
            }
        }else{
            q.push(NULL);
            q.push(NULL);
            arr.push_back(-1);
            arr.push_back(-1);
        }
        }
        for(int i=arr.size()-1;i>=1;i--){
            if(arr[i]==-1){
                continue;
            }
            if(arr[i]==1){
                continue;
            }
            for(int j=i/2;j>=1;j=j/2){
                if(arr[j]==1 or (arr[2*j+1]==1 or arr[2*j]==1 )){
                    continue;
                }else{
                    arr[j]=1;
                }
            }
        }
        for(int i=1;i<arr.size();i++){          
            if(arr[i]==1){
                ans++;
            }
        }
        return ans;
    }
};