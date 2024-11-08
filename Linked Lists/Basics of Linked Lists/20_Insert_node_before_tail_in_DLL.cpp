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
    ListNode* insertBeforeTail(ListNode* head, int X) {
        
        if(head == NULL){
            return NULL;
        }

        ListNode* temp = head;

        if(temp->next == NULL){
            ListNode* newNode = new ListNode(X, temp, nullptr);
            // newNode = head;
            head = newNode;

            temp->prev = newNode;
            return head;
        }

        while(temp->next->next != NULL){
            temp = temp->next;
        }

        ListNode* newNode = new ListNode(X, temp->next, temp);
        temp->next = newNode;
        newNode->next->prev = newNode;
        
        return head;
    }
};