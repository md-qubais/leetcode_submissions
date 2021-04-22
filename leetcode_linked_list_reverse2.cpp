/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void reverse(ListNode*&head,ListNode*&tail){
        ListNode*prev=NULL;
        ListNode*curr=NULL;
        ListNode*next=head;
        tail=head;
        while(next){
            prev=curr;
            curr=next;
            next=next->next;
            curr->next=prev;
        }
        head=curr;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right){
        if(head==NULL){
            return head;
        }
        if(head->next==NULL){
            return head;
        }
        ListNode*prev=NULL;
        ListNode*temp_head=NULL;
        ListNode*temp_tail=NULL;
        ListNode*next=NULL;
        temp_head=head;
        //now here first find temp_head and its prev;
        int f=1;
        while(f!=left){
            prev=temp_head;
            temp_head=temp_head->next;
            f++;
        }
        int s=f;
        
        //now here second find the tail and its next;
        next=temp_head;
        while(s!=right+1){
            temp_tail=next;
            next=next->next;
            s++;
        }
        //now here we have to reverse it;
        //here we are breaking its tail
        temp_tail->next=NULL;
        reverse(temp_head,temp_tail);
        if(prev==NULL){
            head=temp_head;
        }
        else prev->next=temp_head;
        temp_tail->next=next;
        return head;
    }
};