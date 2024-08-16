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
    // Function to find the middle of the list using tortoise and hare approach
    ListNode* getMiddle(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    // Function to merge two sorted lists
    ListNode* merge(ListNode* left, ListNode* right) {
        if (!left) return right;
        if (!right) return left;

        ListNode* dummy = new ListNode(0);
        ListNode* current = dummy;

        while (left && right) {
            if (left->val <= right->val) {
                current->next = left;
                left = left->next;
            } else {
                current->next = right;
                right = right->next;
            }
            current = current->next;
        }

        // If any elements are left in either list, append them
        if (left) current->next = left;
        if (right) current->next = right;

        ListNode* sortedHead = dummy->next;
        delete dummy;
        return sortedHead;
    }

    // Main function to sort the linked list
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;

        // Step 1: Find the middle of the list
        ListNode* middle = getMiddle(head);
        ListNode* rightHalf = middle->next;
        middle->next = nullptr;

        // Step 2: Recursively sort both halves
        ListNode* left = sortList(head);
        ListNode* right = sortList(rightHalf);

        // Step 3: Merge the sorted halves
        return merge(left, right);
    }
};
