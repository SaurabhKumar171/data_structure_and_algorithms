class Solution
{
public:
    bool isPalindrome(ListNode *head)
    {

        ListNode *curr = head;
        stack<int> st;

        while (curr != nullptr)
        {
            st.push(curr->val);
            curr = curr->next;
        }

        curr = head;
        while (curr != nullptr)
        {

            if (curr->val != st.top())
            {
                return false;
            }
            st.pop();
            curr = curr->next;
        }

        return true;
    }
};