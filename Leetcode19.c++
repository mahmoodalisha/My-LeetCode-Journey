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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0); //creating a new node to handle edge cases where head needs to be removed and keep track of the list after removal of a node
        //dummy is a pointer to the object ListNode and new ListNode(0) dynamically allocates memory
        dummy->next = head;
        ListNode* first = dummy; // Initializes a pointer named first and sets it to point to the dummy node.
        ListNode* second = dummy;
        //now move the pointer
        for (int i =0;i<=n;i++){
            first=first->next; 
        }
        //now move both the pointers
        while(first != nullptr){
            first = first->next;
            second = second->next;  //The second pointer will be used to identify the node just before the one to be removed.
        }

        //delete the node from the end
        ListNode* dltNode = second->next;
        second->next=second->next->next; //deleting the desired node
        delete dltNode; //freeing the memory

        //if head is to be removed, rturning the new head
        ListNode* newhead = dummy->next;
        delete dummy;
        return newhead;

    }
};