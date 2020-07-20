/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* node = dummy->next;
        ListNode* pre = dummy;
        while(node)
        {
            if(node->val == val)
            {
                pre->next = node->next;
            }
            else
            {
                pre = node;                
            }
            node = node->next;
        }
        head = dummy->next;
        delete dummy;
        return  head;
    }
};
