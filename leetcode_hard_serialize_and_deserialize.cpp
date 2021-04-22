
class Codec {
public:
    string pre="";
    string ino="";
    void preorder(TreeNode*root){
        if(!root){
            return ;
        }
        if(pre.length()==0){
            pre+=to_string(root->val);
        }else{
            pre+=" "+to_string(root->val);
        }
        preorder(root->left);
        preorder(root->right);
    }
    void inorder(TreeNode*root){
        if(!root){
            return;
        }
        inorder(root->left);
        if(ino.length()==0){
            ino+=to_string(root->val);
        }else{
            ino+=" "+to_string(root->val);
        }
        inorder(root->right);
    }
    string serialize(TreeNode* root){   
        //store inorder and preorder of the tree
        preorder(root);
        inorder(root);
        return pre+"\n"+ino;

    }

    TreeNode* construct(vector<int>&pre,vector<int>&in,int s,int e,int&i){
        if(s>e){
            return NULL;
        }
        TreeNode*root=new TreeNode(pre[i++]);
        int mid;
        for(int j=e;j>=s;j--){
            if(root->val==in[j]){
                mid=j;
                break;
            }
        }
        root->left=construct(pre,in,s,mid-1,i);
        root->right=construct(pre,in,mid+1,e,i);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder){
        int i=0;
        return construct(preorder,inorder,0,preorder.size()-1,i);
    }
    TreeNode* deserialize(string data){    
        TreeNode*root=NULL;
        stringstream str(data);
        string insert;
        vector<string> st;
        while(getline(str,insert,'\n')){
            st.push_back(insert);
        }
        vector<int> p;
        vector<int> i;
        int i_val=0;
        for(auto it:st){
            stringstream lines(it);
            string act;
            while(getline(lines,act,' ')){
                string temp="";
                temp+=act;
                stringstream num(temp);
                int n;
                num>>n;
                if(i_val==0) p.push_back(n);
                else i.push_back(n);
            }
            i_val++;
        }
        return buildTree(p,i);
    }
};
