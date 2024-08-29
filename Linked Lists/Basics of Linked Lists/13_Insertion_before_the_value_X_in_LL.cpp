ListNode* insertBeforeX(ListNode* &head, int X, int val) {
    if(head == NULL){
        return head;
    }
    
    if(head->val == X){
        ListNode* newNode = new ListNode(val, head);
        head = newNode;
        return head;
    }
    ListNode* temp = head;
    while(temp != NULL){
        if(temp->next != NULL && temp->next->val == X){
            ListNode* newNode = new ListNode(val, temp->next);
            temp->next = newNode;
            break;
        }
        temp = temp->next;
    }
    return head;
}