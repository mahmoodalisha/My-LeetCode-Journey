//Reverse Nodes in k-Group

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL) return head;
        
        ListNode* prev = NULL;
        ListNode* current = head;
        ListNode* forward = NULL;
        
        int count = 0;
        // First, check if there are at least k nodes left in the list
        ListNode* temp = head;
        for (int i = 0; i < k; i++) {
            if (temp == NULL) return head; // Not enough nodes to reverse
            temp = temp->next;
        }

        // Reverse k nodes
        while (current != NULL && count < k) {
            forward = current->next;
            current->next = prev;
            prev = current;
            current = forward;
            count++;
        }

        // After reversing k nodes, recursively call for the next group
        if (forward != NULL) {
            head->next = reverseKGroup(forward, k);
        }

        // prev is now the new head of the reversed group
        return prev;
    }
};
