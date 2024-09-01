/*
Definition of doubly linked list:
struct ListNode
{
    int val;
    ListNode *next;
    ListNode *prev;
    ListNode()
    {
        val = 0;
        next = NULL;
        prev = NULL;
    }
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
        prev = NULL;
    }
    ListNode(int data1, ListNode *next1, ListNode *prev1)
    {
        val = data1;
        next = next1;
        prev = prev1;
    }
};
*/

class Solution {
public:
    ListNode* deleteKthElement(ListNode* head, int k) {
       
       if(head == NULL){
        return NULL;
       }

       if(head->next == NULL && k == 1){
        return NULL;
       }

       int cnt = 1;
       ListNode* temp = head;

       while(temp != NULL){

        if(cnt == k){
            break;
        }

        temp = temp->next;
        cnt++;
       }

       if(temp == NULL){
        return head;
       }

       ListNode* Prev = temp->prev;
       ListNode* Next = temp->next;

       if(Prev != NULL && Next != NULL){
            Prev->next = Next;
            Next->prev = Prev;

            delete temp;
            return head;
       }
       else if(Prev == NULL && Next == NULL){
            delete temp;
            return NULL;
       }
       else if(Prev == NULL){
            Next->prev = nullptr;
            delete temp;

            return Next;
       }
       else if(Next == NULL){
            Prev->next = nullptr;
            delete temp;

            return head;
       }

       return head;

    }
};