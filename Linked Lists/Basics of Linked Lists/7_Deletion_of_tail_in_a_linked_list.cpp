/*
Definition of singly linked list:
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
    }
    ListNode(int data1, ListNode *next1)
    {
        val = data1;
        next = next1;
    }
};
*/

class Solution {
public:
    ListNode* deleteTail(ListNode* &head) {
        
        if(head == NULL || head->next == NULL){
            return NULL;
        }

        ListNode* temp = head;

        while(temp->next->next != NULL){
            temp = temp->next;
        }

        delete temp->next;
        temp->next = nullptr;

        return head;
    }
};
