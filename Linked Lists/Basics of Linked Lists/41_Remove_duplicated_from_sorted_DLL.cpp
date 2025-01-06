class Solution
{
public:
    ListNode *removeDuplicates(ListNode *head)
    {
        if (!head)
            return nullptr;

        ListNode *curr = head;
        int previous = INT_MAX;

        while (curr != nullptr)
        {
            if (curr->val == previous)
            {

                ListNode *nextNode = curr->next;
                ListNode *prevNode = curr->prev;

                if (prevNode)
                    prevNode->next = nextNode;
                if (nextNode)
                    nextNode->prev = prevNode;

                delete curr;
                curr = nextNode;
            }
            else
            {
                previous = curr->val;
                curr = curr->next;
            }
        }

        return head;
    }
};