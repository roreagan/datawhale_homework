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
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = l1;
        int step = 0;
        ListNode node(0, l1);
        ListNode* pt = &node;
        while (l1 != nullptr && l2 != nullptr) {
            l1->val += l2->val + step;
            step = l1->val / 10;
            l1->val %= 10;
            l1 = l1->next;
            l2 = l2->next;
            pt = pt->next;
        }
        if (l2 != nullptr) {
            pt->next = l2;
            l1 = l2;
        }
        
        while (l1 != nullptr && step != 0) {
            cout << l1->val << endl;
            l1->val += step;
            step = l1->val / 10;
            l1->val %= 10;
            l1 = l1->next;
            pt = pt->next;
        }
        
        if (step == 1) {
	    // 注意不能用node，node会被释放
            pt->next = new ListNode(1);
        }
        return head;

    }
};
