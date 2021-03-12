## 1. 迭代
```cpp
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head = nullptr;
        ListNode* p = nullptr;
        while (l1 != nullptr || l2 != nullptr) {
            ListNode* pnext;
            if (l1 != nullptr && l2 != nullptr) {
                if (l1->val <= l2->val) {
                    pnext = l1;
                    l1 = l1->next;
                } else {
                    pnext = l2;
                    l2 = l2->next;
                }
            } else if (l1 != nullptr) {
                pnext = l1;
                l1 = l1->next;
            } else {
                pnext = l2;
                l2 = l2->next;
            }

            if (head == nullptr) {
                head = pnext;
                p = head;
            }
            else {
                p->next = pnext;
                p = p->next;
            }
        }

        return head;
    }
};
```
  
## 2. 递归
```cpp
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head = nullptr;
        if (l1 == nullptr)
            head = l2;
        if (l2 == nullptr)
            head = l1;

        if (l1 != nullptr && l2 != nullptr) {
            if (l1->val <= l2->val) {
                head = l1;
                head->next = mergeTwoLists(l1->next, l2);
            }
            else {
                head = l2;
                head->next = mergeTwoLists(l1, l2->next);
            }
        }

        return head;
    }
};
```