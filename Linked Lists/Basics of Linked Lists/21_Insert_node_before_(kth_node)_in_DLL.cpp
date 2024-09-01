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
    ListNode* insertBeforeKthPosition(ListNode* head, int X, int K) {
    
        ListNode* temp = head;

        if(K == 1){
           ListNode* newNode = new ListNode(X, temp, nullptr);
           temp->prev = newNode;

           head = newNode;
           return head;
        }

        int cnt = 1;

        while(temp != NULL){

            if(cnt == K - 1){
                break;
            }

            temp = temp->next;
            cnt++;
        }

        ListNode* nextNode = temp->next;
        ListNode* newNode = new ListNode(X, nextNode, temp);
        temp->next = newNode;
        nextNode->prev = newNode;

        return head;
    }
};