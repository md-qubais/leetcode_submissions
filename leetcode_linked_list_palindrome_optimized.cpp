
class Solution {
public:
    ListNode*left=NULL;
    int len;
    int length(ListNode*head){
        int count=0;
        while(head){
            head=head->next;
            count++;
        }
        return count;
    }
    bool isPalindrome_helper(ListNode* head,int size){
        if(head==NULL){
            return true;
        }
        bool ans=isPalindrome_helper(head->next,size+1);
        if(ans==false){
            return false;
        }
        if(size>len/2){   
            if(head->val==left->val){
                left=left->next;
                return true;
            }else{
                return false;
            }
        }
        return true;
    }

    bool isPalindrome(ListNode*head){
        left=head;
        len=length(head);
        return isPalindrome_helper(head,1);
    }
};