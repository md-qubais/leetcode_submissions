class Solution {
public:
	ListNode*left=NULL;
    bool isPalindrome_helper(ListNode* head){
    	if(head==NULL){
    		return true;
    	}
    	bool ans=isPalindrome_helper(head->next);
    	if(ans==false){
    		return false;
    	}
    	if(head->val==left->val){
    		left=left->next;
    		return true;
    	}
    	return false;
    }
    bool isPalindrome(ListNode*head){
    	left=head;
    	return isPalindrome_helper(head);
    }
};