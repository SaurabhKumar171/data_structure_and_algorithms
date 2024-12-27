// Brute force
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

// optimal soln [T.C - O(n), S.C - O(1)]

class Solution
{
private:
    int sizeOfLL(ListNode *head)
    {
        ListNode *curr = head;
        int cnt = 0;

        while (curr != NULL)
        {
            cnt++;
            curr = curr->next;
        }

        return cnt;
    }

    ListNode *middleNode(ListNode *head)
    {
        int size = sizeOfLL(head);

        int mid = 0;
        if (size % 2 != 0)
        {
            mid = (size + 1) / 2;
        }
        else
        {
            mid = (size / 2) + 1;
        }

        ListNode *curr = head;
        while (mid > 1)
        {
            mid--;
            curr = curr->next;
        }

        return curr;
    }

    ListNode *reverse(ListNode *head)
    {
        ListNode *curr = head;
        ListNode *prev = nullptr;

        while (curr != nullptr)
        {
            ListNode *nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        return prev;
    }

public:
    bool isPalindrome(ListNode *head)
    {

        ListNode *midNode = middleNode(head);
        ListNode *reversedHead = reverse(midNode);

        ListNode *curr = head;
        while (reversedHead != nullptr)
        {
            if (curr->val != reversedHead->val)
            {
                return false;
            }

            curr = curr->next;
            reversedHead = reversedHead->next;
        }

        return true;
    }
};