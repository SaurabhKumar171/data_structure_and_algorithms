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
    ListNode* deleteKthNode(ListNode* &head, int k) {

        if(head == NULL){
            return head;
        }

        if(k == 1){
            head = head->next;
            return head;
        }

        ListNode* temp = head;
        ListNode* prev = nullptr;
        int cnt = 0;
        while(temp != NULL){

            cnt++;
            if(cnt == k){
                prev->next = prev->next->next;
                free(temp);
                break;
            }

            prev = temp;
            temp = temp->next;
        }

        return head;
        
    }
};