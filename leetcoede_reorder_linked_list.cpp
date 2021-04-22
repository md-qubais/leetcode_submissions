class Solution {
public:
	ListNode*left=NULL;
    int size;
    int count;
    int length(ListNode*head){
    	int count=0;
    	while(head){
    		head=head->next;
    		count++;
    	}
    	return count;
    }
    void reorderList_help(ListNode*right){
    	if(right==NULL){
    		return;
    	}
    	reorderList_help(right->next);
    	if(count<size/2){
    		ListNode*temp=left;
    		left=left->next;
    		temp->next=right;
    		right->next=left;
    		count++;
    		return;
    	}
    }
    void reorderList(ListNode* head){
    	left=head;
    	size=length(head);
    	count=0;
    	reorderList_help(head);
    	left->next=NULL;
    }
};