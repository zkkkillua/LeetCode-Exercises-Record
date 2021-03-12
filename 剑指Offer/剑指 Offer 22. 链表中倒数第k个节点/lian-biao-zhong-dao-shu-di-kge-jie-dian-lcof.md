## 1. 快慢指针
不需要先得出n，只需要快指针先走k，然后和慢指针一起走直到快指针到头，相当于二者共同走了n-k，慢指针剩下没走的就是k。  
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
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode* p = head;
        ListNode* res = nullptr;
        while (p != nullptr && --k)
            p = p->next;

        while (p != nullptr) {
            if (res == nullptr)
                res = head;
            else
                res = res->next;
            p = p->next;
        }

        return res;
    }
};
```