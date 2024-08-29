ListNode* arrayToLinkedList(vector<int> &nums) {
    if(nums.size() == 0){
        return NULL;
    }
    ListNode* head = new  ListNode(nums[0]);
    ListNode* temp = head;
    if(nums.size() == 1){
        return head;
    }
    for(int i = 1; i < nums.size(); i++){
        ListNode* newNode = new ListNode(nums[i], nullptr, temp);
        temp->next = newNode;
        temp = temp->next;
    }
    return head;
}