## 1. 栈
使用栈暂存元素，通过先进后出实现逆序输出。   
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
    vector<int> reversePrint(ListNode* head) {
        stack<int> st;
        vector<int> res;

        ListNode* p = head;
        while (p != nullptr) {
            st.push(p->val);
            p = p->next;
        }

        while (!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }

        return res;
    }
};
```
  
## 2. 反转链表
将链表反转，得到的自然是逆序的数据，并且不需要额外的空间。  
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
    vector<int> reversePrint(ListNode* head) {
        vector<int> res;
        head = reverseList(head);
        
        ListNode* p = head;
        while (p != nullptr) {
            res.push_back(p->val);
            p = p->next;
        }
        head = reverseList(head);

        return res;
    }
private:
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = nullptr;
        ListNode* p = head;

        while (p != nullptr) {
            ListNode* temp = p->next;
            p->next = pre;
            pre = p;
            p = temp;
        }

        return pre;
    }
};
```