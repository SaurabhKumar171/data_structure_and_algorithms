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
    void deleteGivenNode(ListNode* node) {

        ListNode* temp = node;

        ListNode* prevNode = temp->prev;
        ListNode* nextNode = temp->next;

        if(nextNode == NULL){
            prevNode->next = nullptr;
            delete temp;

            return;
        }

        prevNode->next = nextNode;
        nextNode->prev = prevNode;

        delete temp;
    }
};