// Brute force([T.C - O(M*N), S.C - O(1)])
class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {

        ListNode *currB = headB;

        while (currB != nullptr)
        {

            ListNode *tempA = headA;
            while (tempA != nullptr)
            {
                if (tempA == currB)
                    return currB;
                tempA = tempA->next;
            }

            currB = currB->next;
        }

        return nullptr;
    }
};

// Better Soln([T.C - O(M)+O(N), S.C - O(M)])
class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        unordered_set<ListNode *> nodeSet;

        ListNode *currB = headB;

        while (currB != nullptr)
        {
            nodeSet.insert(currB);
            currB = currB->next;
        }

        ListNode *currA = headA;

        while (currA != nullptr)
        {

            if (nodeSet.find(currA) != nodeSet.end())
                return currA;
            currA = currA->next;
        }

        return nullptr;
    }
};

// Optimal soln([T.C - O(N + 2N), S.C - O(1)])
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

    ListNode *collisionPoint(ListNode *l1, ListNode *l2, int d)
    {

        while (d)
        {
            l2 = l2->next;
            d--;
        }

        while (l1 != nullptr && l2 != nullptr)
        {
            if (l1 == l2)
                break;
            l1 = l1->next;
            l2 = l2->next;
        }

        return l1;
    }

public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {

        int sizeA = sizeOfLL(headA);
        int sizeB = sizeOfLL(headB);

        ListNode *currB = headB;
        ListNode *currA = headA;

        if (sizeB > sizeA)
        {
            return collisionPoint(headA, headB, sizeB - sizeA);
        }

        return collisionPoint(headB, headA, sizeA - sizeB);
    }
};