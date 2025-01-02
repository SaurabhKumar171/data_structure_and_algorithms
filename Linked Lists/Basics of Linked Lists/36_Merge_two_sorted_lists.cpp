
#include <vector>
#include <iostream>

// N = n1 + n2
// Brute force (T.C - { O(n1 + n2) + O(N(logN)) + O(N) }, S.C - O(N) + O(N))
class ListNode
{
    int val;
    ListNode *next;
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
    }
    ListNode(int data1, ListNode *next1)
    {
        val = data1;
        next = next1;
    }
};

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {

        if (list1 == nullptr && list2 == nullptr)
            return list1;

        vector<int> bucket;

        ListNode *curr = list1;

        while (curr != nullptr)
        {
            bucket.emplace_back(curr->val);
            curr = curr->next;
        }

        curr = list2;

        while (curr != nullptr)
        {
            bucket.emplace_back(curr->val);
            curr = curr->next;
        }

        sort(bucket.begin(), bucket.end());

        ListNode *resultantList = new ListNode(bucket[0]);
        curr = resultantList;

        for (int i = 1; i < bucket.size(); i++)
        {
            ListNode *newNode = new ListNode(bucket[i]);
            curr->next = newNode;
            curr = curr->next;
        }

        return resultantList;
    }
};