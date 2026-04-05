class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head=NULL;
        ListNode* tail=NULL;
        int carry = 0;
        while(l1||l2||carry){
            int sum=carry;
            if(l1){
                sum+=l1->val;
                l1=l1->next;
            }
            if(l2){
                sum+=l2->val;
                l2=l2->next;
            }
            ListNode* newNode=new ListNode(sum%10);
            carry=sum/10;
            if(head==NULL){
                head=newNode;
                tail=newNode;
            }else{
                tail->next=newNode;
                tail=newNode;
            }
        }
        return head;
    }
};
