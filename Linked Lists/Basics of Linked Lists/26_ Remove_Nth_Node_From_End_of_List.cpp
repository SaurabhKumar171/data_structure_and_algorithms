// Brute force solution
class Solution
{
private:
    int sizeOfll(ListNode *head)
    {
        int size = 0;
        ListNode *curr = head;

        while (curr != NULL)
        {
            size++;
            curr = curr->next;
        }

        return size;
    }

public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        int size = sizeOfll(head);
        int nodeToDelete = size - n;

        if (nodeToDelete == 0)
        {
            ListNode *newHead = head->next;
            delete head;
            return newHead;
        }

        ListNode *curr = head;

        while (curr != NULL)
        {

            if (nodeToDelete == 1)
            {
                ListNode *delNode = curr->next;
                curr->next = curr->next->next;
                delete delNode;
                break;
            }
            curr = curr->next;
            nodeToDelete--;
        }

        return head;
    }
};

// Optimal solution
class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {

        ListNode *slow = head;
        ListNode *fast = head;

        for (int i = 0; i < n; i++)
        {
            fast = fast->next;
        }

        if (fast == NULL)
        {
            return head->next;
        }

        while (fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }

        ListNode *delNode = slow->next;
        slow->next = slow->next->next;
        delete delNode;
        return head;
    }
};