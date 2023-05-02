// leetcode 160

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr){};
  ListNode(int x, ListNode *ptr = nullptr) : val(x), next(ptr){};
};

class Solution {
public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode *ptrA = headA;
    ListNode *ptrB = headB;
    while (ptrA != ptrB) {
      if (ptrA != nullptr) {
        ptrA = ptrA->next;
      } else {
        ptrA = headB;
      }
      if (ptrB != nullptr) {
        ptrB = ptrB->next;
      } else {
        ptrB = headA;
      }
    }
    if(ptrA!=nullptr)
      return ptrA;
    return nullptr;
  }
};