// Brute force([T.C - O(N), S.C - O(N)])
class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        unordered_set<ListNode *> st;

        ListNode *curr = head;

        while (curr != nullptr)
        {
            if (st.find(curr) != st.end())
            {
                return true;
            }
            else
            {
                st.insert(curr);
            }

            curr = curr->next;
        }

        return false;
    }
}

// Optimal soln([T.C - O(N), S.C - O(1)])  - Tortoise ans hare soln
class Solution
{
public:
    bool hasCycle(ListNode *head)
    {

        ListNode *slow = head;
        ListNode *fast = head;

        while (fast != nullptr && fast->next != nullptr)
        {

            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
            {
                return true;
            }
        }

        return false;
    }
};