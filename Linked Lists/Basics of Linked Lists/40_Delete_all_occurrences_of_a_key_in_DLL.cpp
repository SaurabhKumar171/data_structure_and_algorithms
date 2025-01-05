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
// Soln (T.C - { O(N)}, S.C - O(1))
class Solution
{
public:
    ListNode *deleteAllOccurrences(ListNode *head, int target)
    {

        ListNode *curr = head;

        while (curr != nullptr)
        {
            if (curr->val == target)
            {

                if (curr == head)
                {
                    head = curr->next;
                }

                ListNode *nextNode = curr->next;
                ListNode *prevNode = curr->prev;

                if (nextNode)
                    nextNode->prev = prevNode;
                if (prevNode)
                    prevNode->next = nextNode;

                delete curr;
                curr = nextNode;
            }
            else
            {
                curr = curr->next;
            }
        }

        return head;
    }
};