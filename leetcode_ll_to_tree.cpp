
//dynamic programming 
class Solution {
public:
    bool isSubPath(ListNode* head, TreeNode* root){
        if(!root==NULL and !head){
            return true;
        }
        if(!root){
            return false;
        }
        if(!head){
            return true;
        }
        bool op1;
        if(head  and head->val==root->val){
            op1=isSubPath(head->next,root->left);
        }
        if(op1){
            return true;
        }
        bool op2;
        if(head and head->val==root->val){
            op2=isSubPath(head->next,root->right);
        }
        if(op2){
            return true;
        }
        bool op3=isSubPath(head,root->left);
        if(op3){
            return true;
        }
        bool op4=isSubPath(head,root->right);
        return op4;
    }
};