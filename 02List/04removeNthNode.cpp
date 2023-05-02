// leetcode 19

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr){};
  ListNode(int x, ListNode *ptr = nullptr) : val(x), next(ptr){};
};

class Solution {
public:
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    ListNode *dummyHead = new ListNode(96);
    dummyHead->next = head;
    ListNode *slow = dummyHead;
    ListNode *fast = dummyHead->next;
    while (n) {
      fast = fast->next;
      n--;
    }
    while(fast!=nullptr){
        slow=slow->next;
        fast=fast->next;
    }
    ListNode *temp = slow->next->next;
    delete slow->next;
    slow->next = temp;
    ListNode *result = dummyHead->next;
    delete dummyHead;
    return result;
  }
};