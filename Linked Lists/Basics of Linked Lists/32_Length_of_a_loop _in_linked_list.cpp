
// Brute force (T.C - O(n), S.C - O(n))
class Solution
{
public:
    int findLengthOfLoop(ListNode *head)
    {
        int timer = 1;

        unordered_map<ListNode *, int> mp;

        ListNode *curr = head;

        while (curr != nullptr)
        {
            if (mp.find(curr) != mp.end())
            {
                return timer - mp[curr];
            }
            else
            {
                mp[curr] = timer;
            }

            timer++;
            curr = curr->next;
        }

        return 0;
    }
};

// Optimal Aproach (T.C - O(n), S.C - O(1))
class Solution
{
public:
    int findLengthOfLoop(ListNode *head)
    {

        ListNode *slow = head;
        ListNode *fast = head;

        while (fast != nullptr && fast->next != nullptr)
        {

            fast = fast->next->next;
            slow = slow->next;

            if (fast == slow)
            {
                int counter = 1;
                fast = slow->next;
                while (fast != slow)
                {
                    fast = fast->next;
                    counter++;
                }
                return counter;
            }
        }

        return 0;
    }
};