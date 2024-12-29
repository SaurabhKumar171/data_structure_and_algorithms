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

// Optimal Solution
class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;

        bool loopExists = false;

        while (fast != nullptr && fast->next != nullptr)
        {

            fast = fast->next->next;
            slow = slow->next;

            if (fast == slow)
            {
                slow = head;

                while (slow != fast)
                {

                    fast = fast->next;
                    slow = slow->next;
                }

                return slow;
            }
        }

        return nullptr;
    }
};