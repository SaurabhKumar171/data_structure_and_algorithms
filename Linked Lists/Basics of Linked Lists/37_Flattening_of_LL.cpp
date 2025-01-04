
// Brute force (T.C - {O(N*M) + O(N*M(log(N*M))) + O(N*M)}}, S.C -{O(N*M) + O(N*M)})
class Solution

{
public:
    ListNode *flattenLinkedList(ListNode *&head)
    {
        ListNode *curr = head;
        vector<int> bucket;

        while (curr != nullptr)
        {

            ListNode *temp = curr;

            while (temp != nullptr)
            {
                bucket.push_back(temp->val);
                temp = temp->child;
            }

            curr = curr->next;
        }

        sort(bucket.begin(), bucket.end());

        ListNode *dummyNode = new ListNode(-1);
        ListNode *temp = dummyNode;

        for (int i = 0; i < bucket.size(); i++)
        {
            temp->child = new ListNode(bucket[i]);
            temp = temp->child;
        }

        return dummyNode->child;
    }
};