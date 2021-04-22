class Solution {
public:
    bool isPalindrome(ListNode* head){
    	stack<ListNode*> s;
    	ListNode*temp=head;
    	while(temp){
    		s.push(temp);
    		temp=temp->next;
    	}
    	while(!s.empty()){
    		if(s.top()->val!=head->val){
    			return false;
    		}
    		s.pop();
    		head=head->next;
    	}
    	return true;
    }
};