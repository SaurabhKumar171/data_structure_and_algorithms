// struct ListNode
// {
//     int val;
//     ListNode *next;
//     ListNode()
//     {
//         val = 0;
//         next = NULL;
//     }
//     ListNode(int data1)
//     {
//         val = data1;
//         next = NULL;
//     }
//     ListNode(int data1, ListNode *next1)
//     {
//         val = data1;
//         next = next1;
//     }
// };

// Brute force solution (using extra space)
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

// Brute force solution (without using extra space)
class Solution
{
public:
    ListNode *sortList(ListNode *head)
    {

        int zeroCount = 0;
        int oneCount = 0;
        int twoCount = 0;

        ListNode *curr = head;

        while (curr != NULL)
        {
            if (curr->val == 0)
                zeroCount++;
            else if (curr->val == 1)
                oneCount++;
            else if (curr->val == 2)
                twoCount++;

            curr = curr->next;
        }

        curr = head;

        while (curr != NULL)
        {
            if (zeroCount > 0)
            {
                curr->val = 0;
                zeroCount--;
            }
            else if (oneCount > 0)
            {
                curr->val = 1;
                oneCount--;
            }
            else if (twoCount > 0)
            {
                curr->val = 2;
                oneCount--;
            }
            curr = curr->next;
        }

        return head;
    }
};