
//  * Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *oddEvenList(ListNode *head)
    {
        ListNode *evenList = new ListNode(-1);
        ListNode *oddList = new ListNode(-1);

        ListNode *currEven = evenList;
        ListNode *currOdd = oddList;

        ListNode *curr = head;
        int id = 1;

        while (curr != nullptr)
        {

            ListNode *newNode = new ListNode(curr->val);

            if (id % 2 != 0)
            {
                currOdd->next = newNode;
                currOdd = newNode;
            }
            else
            {
                currEven->next = newNode;
                currEven = newNode;
            }

            id++;
            curr = curr->next;
        }

        currOdd->next = evenList->next;

        return oddList->next;
    }
};