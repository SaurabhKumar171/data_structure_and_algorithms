
// Brute force (T.C - O(n), O(n))
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