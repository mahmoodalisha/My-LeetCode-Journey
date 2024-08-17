//merge 2 sorted linkedlist
//first and second are the two linked list respectively
//current1 and current2 are the first nodes of the two linked lists

Node<int>* solve(Node<int>* first, Node<int>* second){

    Node* current1 = first;
    Node* current2 = second;
    Node* next1 = current1->next;
    Node* next2 = current2->next;

    while(next1 !=NULL && current2 != NULL){
        if (current2 ->data >= current1->data && current2->data <=next1 -> data){
            current1->next = current2;
            current2 -> next = next1

            //updating the pointers
            current1 = current2;
            current2 = next2;
        }
        else{
            //agar 2nd linkedlist me koi element nahi mila jo 1st linkedlist se bada hai to aage badha do
            //current1 aur next1 ko aage badha do aur last me current1 ke baad 2nd linked list se merge kardo
            current1 = current1->next;
            next1 = next1->next;
            if(next1 == NULL){
                current1 -> next = current2;
                return first;

            }
        }
    }
    return first;
}

Node<int>* sortTwoLists(Node<int>* first, Node<int>* second){
    if (first == NULL)
    return second;
    if (second == NULL)
    return first;

    if (first -> data <second ->data){
        solve(first, second);
    }
    else{
        solve(second, first);
    }
}