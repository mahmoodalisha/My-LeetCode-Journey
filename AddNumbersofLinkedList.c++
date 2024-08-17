class Solution {
    private:
    // Function to reverse a linked list
    ListNode* reverseLinkedList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* current = head;
        ListNode* forward = NULL;
        
        while (current != NULL) {
            forward = current->next;
            current->next = prev;
            prev = current;
            current = forward;
        }
        return prev;
    }
    
    // Function to insert a new node at the tail of the list
    void insertAtTail(ListNode*& head, ListNode*& tail, int data) {
        ListNode* temp = new ListNode(data);
        if (head == NULL) {
            head = temp;
            tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
    }
    
    // Function to add two reversed linked lists
    ListNode* add(ListNode* first, ListNode* second) {
        int carry = 0;
        ListNode* ansHead = NULL;
        ListNode* ansTail = NULL;
        
        while (first != NULL || second != NULL || carry != 0) {
            int sum = carry;
            if (first != NULL) {
                sum += first->val;
                first = first->next;
            }
            if (second != NULL) {
                sum += second->val;
                second = second->next;
            }
            int digit = sum % 10;
            carry = sum / 10;
            
            insertAtTail(ansHead, ansTail, digit);
        }
        
        return ansHead;
    }

public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // Reverse both lists
        ListNode* first = reverseLinkedList(l1);
        ListNode* second = reverseLinkedList(l2);
        
        // Add the two numbers
        ListNode* ans = add(first, second);
        
        // Reverse the result list to get the final answer
        ans = reverseLinkedList(ans);
        
        return ans;
    }
};