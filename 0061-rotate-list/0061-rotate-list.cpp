class Solution {
    ListNode* rotate(ListNode* head) {
        ListNode* t = head;
        while (t->next->next) {
            t = t->next;}
        ListNode* adr = t->next;
        t->next = NULL;
        adr->next = head;
        head = adr;
        return head;}
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr)
            return head;
        int c = 1;
        ListNode* t = head;
        while (t->next) {
            t = t->next;
            c++; }
        k = k % c;
        for (int i = 1; i <= k; i++) {
            head = rotate(head);}
        return head;}};