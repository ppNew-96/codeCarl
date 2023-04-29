// leetcode 206

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr){};
  ListNode(int x, ListNode *ptr = nullptr) : val(x), next(ptr){};
};

// no recursive version
// class Solution {
// public:
//   ListNode *reverseList(ListNode *head) {
//     ListNode *cur = head;
//     ListNode *pre = nullptr;
//     while (cur != nullptr) {
//       ListNode *temp = cur->next;
//       cur->next = pre;
//       pre = cur;
//       cur = temp;
//     }
//     return pre;
//   }
// };

// recursive version:
// sub-problem: reverse and return new head node
class Solution {
public:
  ListNode *reverseList(ListNode *head) {
    if (head == nullptr)
      return nullptr;
    if (head->next == nullptr)
      return head;
    ListNode *last = reverseList(head->next);
    head->next->next = head;
    head->next = nullptr;
    return last;
  }
};