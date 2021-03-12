## 1. 迭代
```cpp
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = nullptr;
        ListNode* p = head;
        while (p != nullptr) {
            ListNode* pnext = p->next;
            p->next = pre;
            pre = p;
            p = pnext;
        }

        return pre;
    }
};
```
  
## 2. 递归
1->(2->3->4->5)rev  
1->(2<-3<-4<-5)  
<-1<-2-<3<-4<-5  
```cpp
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode* newHead = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;

        return newHead;
    }
};
```