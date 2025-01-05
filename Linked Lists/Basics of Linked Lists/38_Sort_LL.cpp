// Brute force (T.C - {O(N) + O(N log N) + O(N)}, S.C -{O(N)})
class Solution
{
public:
    ListNode *sortList(ListNode *head)
    {
        vector<int> bucket;

        ListNode *curr = head;

        while (curr != nullptr)
        {
            bucket.push_back(curr->val);
            curr = curr->next;
        }

        sort(bucket.begin(), bucket.end());

        ListNode *dummyNode = new ListNode(-1);
        curr = dummyNode;
        for (int i = 0; i < bucket.size(); i++)
        {
            curr->next = new ListNode(bucket[i]);
            curr = curr->next;
        }

        return dummyNode->next;
    }
};