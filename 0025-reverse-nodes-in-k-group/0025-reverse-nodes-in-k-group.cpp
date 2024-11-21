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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head; 
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prevGroupEnd = dummy;
        while (true) {
            ListNode* groupStart = prevGroupEnd->next;
            ListNode* groupEnd = prevGroupEnd;
            for (int i = 0; i < k; i++) {
                groupEnd = groupEnd->next;
                if (!groupEnd) {
                    return dummy->next; 
                }
            }
            ListNode* nextGroupStart = groupEnd->next;
            reverseGroup(groupStart, groupEnd);
            prevGroupEnd->next = groupEnd;
            groupStart->next = nextGroupStart;
            prevGroupEnd = groupStart;
        }
    }

private:
    void reverseGroup(ListNode* start, ListNode* end) {
        ListNode* prev = nullptr;
        ListNode* curr = start;
        ListNode* stop = end->next;

        while (curr != stop) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
    }
};
