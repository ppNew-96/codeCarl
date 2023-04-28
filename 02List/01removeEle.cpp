// leetcode 203
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr){};
  ListNode(int x, ListNode *ptr = nullptr) : val(x), next(ptr){};
};

class Solution {
public:
  ListNode *removeElements(ListNode *head, int val) {
    ListNode *dummyHead = new ListNode(0);
    dummyHead->next = head;
    ListNode *curPtr = dummyHead;

    //dummyHead unifies the operation.
    while (curPtr->next != nullptr) {
      if (curPtr->next->val == val) {
        ListNode *temp = curPtr->next;
        curPtr->next = temp->next;
        delete temp;
      } else {
        curPtr = curPtr->next;
      }
    }
    head = dummyHead->next;
    delete dummyHead;
    return head;
  }
};