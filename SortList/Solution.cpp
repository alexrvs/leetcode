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
        ListNode* merge(ListNode* h1, ListNode* h2) {
            ListNode* head = new ListNode(0);
            ListNode* p = head;
            while(h1!=NULL && h2!=NULL) {
                if(h1->val<h2->val){
                    p->next = h1;
                    h1 = h1->next;
                } else {
                    p->next = h2;
                    h2 = h2->next;
                }
                p = p->next;
            }

            if(h1!=NULL)
                p->next = h1;
            else
                p->next = h2;
            ListNode* merged = head->next;
            delete head;
            return merged;
        }

        ListNode* mergeSort(ListNode* head) {
            if(head == NULL || head->next == NULL)
                return head;
            ListNode* p=head;
            ListNode* q=head;
            ListNode* pre = p;
            while(q != NULL && q->next != NULL) {
                q=q->next->next;
                pre = p;
                p=p->next;
            }
            pre->next = NULL;
            return merge(mergeSort(head), mergeSort(p));
        }

        ListNode *sortList(ListNode *head) {
            return mergeSort(head);
        }
};
