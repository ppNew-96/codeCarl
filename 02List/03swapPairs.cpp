// leetcode 24
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr){};
  ListNode(int x, ListNode *ptr = nullptr) : val(x), next(ptr){};
};

class Solution {
public:
  ListNode *swapPairs(ListNode *head) {
    ListNode *dummyHead = new ListNode(96);
    dummyHead->next = head;
    ListNode *cur = dummyHead;
    // swap two nodes and connect them to the previous one.
    // dummyHead unified operations.
    while (cur->next != nullptr && cur->next->next != nullptr) {
      ListNode *temp1 = cur->next;
      ListNode *temp2 = cur->next->next->next;
      cur->next->next->next = temp1;
      cur->next = temp1->next;
      temp1->next = temp2;

      cur = cur->next->next;
    }
    ListNode *result = dummyHead->next;
    delete dummyHead;
    return result;
  }
};