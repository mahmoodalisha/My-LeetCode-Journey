//reverse linkedlist according to k given groups
Node *kReverse(Node* head, int k) {
    if (head == NULL ){
        return head;
    }
    //step1: reverse first k nodes
    Node* prev = NULL;
    Node* current = head;
    Node* forward = NULL;
    int count = 0;
    while (current !=NULL && count < k){
        forward = current->next;
        current ->next = prev;
        prev = current;
        current = forward;
    }

    //recursion dekhlega aage
    if (prev! = NULL){
        head -> next = kReverse(prev, k)
    }
}