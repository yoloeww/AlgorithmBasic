class Solution {
public:
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
         int lenA = 0,lenB = 0;
		 ListNode* curA = pHead1;
		 ListNode* curB = pHead2;
		 while (curA != nullptr) {
			curA = curA -> next;
			lenA++;
		 }
		 while (curB != nullptr) {
			curB = curB -> next;
			lenB++;
		 }
		curA = pHead1;
        curB = pHead2;
		if (lenA > lenB) {
			int dif = lenA - lenB;
			while (dif--)
			curA = curA -> next;
		}
		else {
			int dif = lenB - lenA;
			while (dif --) {
				curB = curB -> next;
			}
		}
		while (curA != nullptr && curB != nullptr) {
				if (curA == curB) {
					return curA;
				}
				curA = curA -> next;
				curB = curB -> next;
		}
		return nullptr;
    }
};
