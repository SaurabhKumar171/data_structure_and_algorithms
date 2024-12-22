

// Brute force
struct ListNode
{
    int val;
    ListNode *next;
    ListNode *prev;
    ListNode()
    {
        val = 0;
        next = nullptr;
        prev = nullptr;
    }
    ListNode(int data1)
    {
        val = data1;
        next = nullptr;
        prev = nullptr;
    }
    ListNode(int data1, ListNode *next1, ListNode *prev1)
    {
        val = data1;
        next = next1;
        prev = prev1;
    }
};

class Solution
{
public:
    void insertBeforeGivenNode(ListNode *node, int X)
    {

        ListNode *temp = node;

        ListNode *prevNode = node->prev;

        // create a new node
        ListNode *newNode = new ListNode(X, temp, prevNode);
        prevNode->next = newNode;
        temp->prev = newNode;
    }
};

// Optimal Solution
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *oddEvenList(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return head;

        ListNode *odd = head;
        ListNode *even = head->next;
        ListNode *firstEven = head->next;

        while (even != NULL && even->next != NULL)
        {
            odd->next = odd->next->next;
            even->next = even->next->next;

            odd = odd->next;
            even = even->next;
        }

        odd->next = firstEven;

        return head;
    }
};