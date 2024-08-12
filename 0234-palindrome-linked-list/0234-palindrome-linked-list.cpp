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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr != nullptr) {
            ListNode* next_node = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next_node;
        }
        return prev;
    }

    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return true;
        }

        // Step 1: Find the middle of the list
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Reverse the second half of the list
        ListNode* second_half = reverseList(slow);

        // Step 3: Compare the first and second half
        ListNode* first_half = head;
        ListNode* second_half_copy = second_half;
        bool is_palindrome = true;
        while (second_half_copy != nullptr) {
            if (first_half->val != second_half_copy->val) {
                is_palindrome = false;
                break;
            }
            first_half = first_half->next;
            second_half_copy = second_half_copy->next;
        }

        // Step 4: (Optional) Restore the list
        reverseList(second_half);

        return is_palindrome;
    }
};

