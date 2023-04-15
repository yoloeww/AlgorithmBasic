class Solution {
public:
    //反转链表
    ListNode* ReverseList(ListNode* pHead) {
        if(pHead == nullptr)
            return nullptr;
        ListNode* cur = pHead;
        ListNode* pre = nullptr;
        while(cur != nullptr){
            //断开链表，要记录后续一个
            ListNode* temp = cur->next;
            //当前的next指向前一个
            cur->next = pre;
            //前一个更新为当前
            pre = cur;
            //当前更新为刚刚记录的后一个
            cur = temp;
        }
        return pre;
    }
     
    ListNode* addInList(ListNode* head1, ListNode* head2) {
        //任意一个链表为空，返回另一个
        if(head1 == nullptr)
            return head2;
        if(head2 == nullptr)
            return head1;
        //反转两个链表
        head1 = ReverseList(head1);
        head2 = ReverseList(head2);
        //添加表头
        ListNode* res = new ListNode(-1);
        ListNode* head = res;
        //进位符号
        int carry = 0;
        //只要某个链表还有或者进位还有
        while(head1 != nullptr || head2 != nullptr || carry != 0){
            //链表不为空则取其值
            int val1 = head1 == nullptr ? 0 : head1->val;
            int val2 = head2 == nullptr ? 0 : head2->val;
            //相加
            int temp = val1 + val2 + carry;
            //获取进位
            carry = temp / 10;
            temp %= 10;
            //添加元素
            head -> next = new ListNode(temp);
            head = head -> next;
            //移动下一个
            if(head1 != nullptr)
                head1 = head1->next;
            if(head2 != nullptr)
                head2 = head2->next;
        }
        //结果反转回来
        return ReverseList(res->next);
    }
};
