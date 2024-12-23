// Brute force solution

struct ListNode
{
    int val;
    ListNode *next;
    ListNode()
    {
        val = 0;
        next = NULL;
    }
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

class Solution
{
public:
    ListNode *sortList(ListNode *head)
    {
        vector<int> store;

        ListNode *curr = head;

        while (curr != NULL)
        {
            store.push_back(curr->val);
            curr = curr->next;
        }

        sort(store.begin(), store.end());

        ListNode *res = new ListNode(-1);
        ListNode *resCurr = res;

        for (int i = 0; i < store.size(); i++)
        {
            ListNode *newNode = new ListNode(store[i]);

            resCurr->next = newNode;
            resCurr = newNode;
        }

        return res->next;
    }
};