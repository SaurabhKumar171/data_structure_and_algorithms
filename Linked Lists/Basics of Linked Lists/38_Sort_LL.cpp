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

// Optimal Soln (T.C - { O(nlong * (n+n/2))}, S.C - O(logn))
class Solution
{
private:
    ListNode *mergeLL(ListNode *left, ListNode *right)
    {
        ListNode *dummyNode = new ListNode(-1);
        ListNode *curr = dummyNode;

        while (left != nullptr && right != nullptr)
        {
            if (left->val <= right->val)
            {
                curr->next = left;
                left = left->next;
            }
            else
            {
                curr->next = right;
                right = right->next;
            }

            curr = curr->next;
        }

        while (left != nullptr)
        {
            curr->next = left;
            left = left->next;
            curr = curr->next;
        }

        while (right != nullptr)
        {
            curr->next = right;
            right = right->next;
            curr = curr->next;
        }

        return dummyNode->next;
    }

    ListNode *findMiddle(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;

        while (fast->next != nullptr && fast->next->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

public:
    ListNode *sortList(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode *mid = findMiddle(head);

        ListNode *leftHead = head;
        ListNode *rightHead = mid->next;
        mid->next = nullptr;

        leftHead = sortList(leftHead);
        rightHead = sortList(rightHead);

        return mergeLL(leftHead, rightHead);
    }
};