```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        ListNode* pre = nullptr;
        ListNode* p = head;
        
        while (p != nullptr && p->val != val) {
            pre = p;
            p = p->next;
        }
        if (p != nullptr) {
            if (p == head) {
                head = p->next;
                p->next = nullptr;
            } else {
                pre->next = p->next;
                p->next = nullptr;
            }
        }

        return head;
    }
};
```