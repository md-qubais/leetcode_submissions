class Solution {
public:
	int length(ListNode*a){
		int len=0;
		while(a){
			a=a->next;
			len++;
		}
		return len;
	}
    ListNode *getIntersectionNode(ListNode *a, ListNode *b){
    	int len_a=length(a);
    	int len_b=length(b);
    	ListNode*ans=NULL;
    	if(len_a<len_b){
    		ListNode*temp=a;
    		a=b;
    		b=temp;
    		swap(len_a,len_b);
    	}
    	int len=len_a - len_b;
    	while(a and len--){
    		a=a->next;
    	}
       while(a and b){
    		if(a==b){
    			ans=a;
    			return a;
    		}
    		a=a->next;
    		b=b->next;
    	}
    	return ans;
    }
};