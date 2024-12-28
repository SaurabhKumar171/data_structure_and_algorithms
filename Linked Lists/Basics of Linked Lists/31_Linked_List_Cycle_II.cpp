// Brute force
class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        unordered_set<ListNode *> st;

        ListNode *curr = head;

        while (curr != nullptr)
        {
            if (st.find(curr) != st.end())
            {
                return curr;
            }
            else
            {
                st.insert(curr);
            }

            curr = curr->next;
        }

        return nullptr;
    }
};