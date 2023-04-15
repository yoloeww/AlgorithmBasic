class Solution {
public:
    /**
     * 
     * @param head ListNode类 
     * @param k int整型 
     * @return ListNode类
     */
    ListNode* reverse(ListNode* root) {
        if(root==nullptr || root->next==nullptr)
            return root;
        ListNode *a=nullptr, *b=root, *c=root->next;
        while(c!=nullptr) {
            b->next=a;
            a=b;
            b=c;
            c=c->next;
        }
        b->next=a;
        return b;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==nullptr || head->next==nullptr || k<=1)
            return head;
        ListNode * root=new ListNode(0);
        root->next=head;
        ListNode* pre=root;
        ListNode* cur=head;
        int count=1;
        while(cur!=nullptr) {
            cur=cur->next;
            ++count;
            if(cur!=nullptr && count==k) {
                ListNode* start=pre->next;
                ListNode* aft=cur->next;
                cur->next=nullptr;
                pre->next=reverse(start);
                start->next=aft;
                pre=start;
                cur=aft;
                count=1;
            }
        }
        return root->next;
    }
};
