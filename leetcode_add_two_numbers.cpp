class Solution {
public:
	int length(ListNode*head){
		int count=0;
		while(head){
			head=head->next;
			count++;
		}
		return count;
	}
	int mod=0;
	void addTwoNumbers(ListNode*a,ListNode*b,int size_a,int size_b){
		if(a==NULL and b==NULL){
			return;
		}
		if(size_a==size_b){
			addTwoNumbers(a->next,b->next,size_a-1,size_b-1);
			int num=a->val+b->val+mod;
			mod=num/10;
			a->val=num%10;
		}else{
			addTwoNumbers(a->next,b,size_a-1,size_b);
			int num=a->val+mod;
			mod=num/10;
			a->val=num%10;
		}
	}
    ListNode* addTwoNumbers(ListNode*a, ListNode*b) {
        int size_a=length(a);
        int size_b=length(b);
        if(size_a<size_b){
        	ListNode*temp=a;
        	a=b;
        	b=temp;
        	swap(size_a,size_b);
        }
        //now always a is greater than or equal to b
        addTwoNumbers(a,b,size_a,size_b);
        if(mod>0){
        	ListNode*temp=new ListNode(mod);
        	temp->next=a;
        	a=temp;
        }
        return a;
    }
};