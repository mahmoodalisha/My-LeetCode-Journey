bool isCircularList(Node* head){
    if(head==NULL){  //when head is null, list is empty
        return true;
    }
    Node* temp = head->next;
    while(temp != NULL && temp != head){
        temp = temp->next;
    }
    if (temp==head){
        return true;
    }
    return false;
}