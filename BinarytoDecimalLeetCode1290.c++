class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int result = 0;
        while (head != nullptr) {
            result = result * 2 + head->val;  // shift left and add the bit
            head = head->next;                // move to next node
        }
        return result;
    }
};
/*
Let's say result = 3
In binary: 3 = 011
result = result * 2; i.e 3 * 2 = 6

In binary:
011 becomes 110 → which is 6
That’s a left shift: bits move one place to the left.
