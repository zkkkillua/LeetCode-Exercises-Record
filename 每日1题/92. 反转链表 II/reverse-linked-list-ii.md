## 1. 迭代
```cpp
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* pre = nullptr;
        ListNode* p = head;
        ListNode* subHead;
        ListNode* subHeadPre;
        ListNode* pnext = p->next;

        for (int i = 1; i <= right ; i++) {
            if (i < left) {
                pre = p;
                p = p->next;
            } else if (i == left) {
                subHeadPre = pre;
                subHead = p;
                pre = p;
                p = p->next;
            }
            else if (i > left) {
                pnext = p->next;
                p->next = pre;
                pre = p;
                p = pnext;
            }
        }
        subHead->next = p;
        if (subHeadPre != nullptr)
            subHeadPre->next = pre;
        
        return left == 1 ? pre : head;
    }
};
```