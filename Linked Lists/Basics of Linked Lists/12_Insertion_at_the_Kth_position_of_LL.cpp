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
    ListNode* insertAtKthPosition(ListNode* &head, int X, int K) {

        ListNode* newNode = new ListNode(X);
        ListNode* temp = head;
        // cout << "tt " << head->val << endl;

        if(K == 1){
            newNode->next = head;
            head = newNode;

            return head;
        }

        int cnt = 0;
        while(temp != NULL){

            cnt++;

            if(cnt == K - 1){
                newNode->next = temp->next;
                temp->next = newNode;
                break;
                // cout << "tt " << newNode->val << " cnt " << cnt << endl;
            }

            temp = temp->next;
        }


        return head;
    }
};