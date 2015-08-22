/**
* Definition for singly-linked list.
* struct ListNode {
* int val;
* ListNode *next;
* ListNode(int x) : val(x), next(NULL) {}
* };
*/
class Solution {
public:
  bool hasCycle(ListNode *head) {
    ListNode* pfast = head;
    ListNode* pslow = head;
    do{
      if(pfast!=NULL)
      pfast=pfast->next;
      if(pfast!=NULL)
      pfast=pfast->next;
      if(pfast==NULL)
      return false;
      pslow = pslow->next;
    }while(pfast != pslow);
    return true;
  }
};
