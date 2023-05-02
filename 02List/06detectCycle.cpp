// leetcode 142

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr){};
  ListNode(int x, ListNode *ptr = nullptr) : val(x), next(ptr){};
};

class Solution {
public:
  ListNode *detectCycle(ListNode *head) {
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast != nullptr && fast->next != nullptr) {
      slow = slow->next;
      fast = fast->next->next;
      if (slow == fast) {
        ListNode *temp1 = head;
        ListNode *temp2 = fast;
        while (temp1 != temp2) {
          temp1 = temp1->next;
          temp2 = temp2->next;
        }
        return temp1;
      }
    }
    return nullptr;
  }
};