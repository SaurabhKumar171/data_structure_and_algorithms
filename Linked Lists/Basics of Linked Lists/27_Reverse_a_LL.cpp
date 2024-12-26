
// Brute force
class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {

        if (head == NULL || head->next == NULL)
            return head;

        ListNode *curr = head;
        ListNode *temp = nullptr;

        while (curr != nullptr)
        {
            ListNode *newNode = new ListNode(curr->val);
            newNode->next = temp;
            temp = newNode;
            curr = curr->next;
        }

        return temp;
    }
};

// optimal (iterative) solution
class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return head;

        ListNode *prev = nullptr;
        ListNode *curr = head;

        while (curr != nullptr)
        {
            ListNode *nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        return prev;
    }
};

// optimal (recursive) solution
class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {

        if (head == NULL || head->next == NULL)
            return head;

        ListNode *newHead = reverseList(head->next);

        ListNode *front = head->next;
        front->next = head;
        head->next = nullptr;

        return newHead;
    }
};