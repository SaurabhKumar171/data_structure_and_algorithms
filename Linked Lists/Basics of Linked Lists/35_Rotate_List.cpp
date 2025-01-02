
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Brute force (T.C - O(n + n/2), S.C - O(1))
class Solution
{
private:
    ListNode *rotateList(ListNode *head)
    {

        ListNode *curr = head;
        ListNode *temp = head;
        ListNode *prev = nullptr;

        while (curr->next != nullptr)
        {
            prev = curr;
            curr = curr->next;
        }

        curr->next = temp;
        prev->next = nullptr;
        head = curr;

        return head;
    }

public:
    ListNode *rotateRight(ListNode *head, int k)
    {

        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode *newHead = head;
        for (int i = k; i > 0; i--)
        {
            newHead = rotateList(newHead);
        }

        return newHead;
    }
};

// Optimal approach
class Solution
{
private:
    ListNode *rotateList(ListNode *head, int pivot)
    {

        ListNode *curr = head;
        ListNode *temp = head;
        ListNode *prev = nullptr;

        while (pivot && curr->next != nullptr)
        {
            pivot--;
            prev = curr;
            curr = curr->next;
        }

        ListNode *endNode = head;
        while (endNode->next != nullptr)
        {
            endNode = endNode->next;
        }

        endNode->next = temp;
        prev->next = nullptr;
        head = curr;

        return head;
    }

    int getLength(ListNode *head)
    {
        ListNode *curr = head;
        int len = 0;
        while (curr != nullptr)
        {
            len++;
            curr = curr->next;
        }

        return len;
    }

public:
    ListNode *rotateRight(ListNode *head, int k)
    {

        int lengthOfLL = getLength(head);

        if (head == nullptr || head->next == nullptr || (k % lengthOfLL) == 0)
            return head;

        int pivot = 0;

        if (lengthOfLL < k)
        {
            pivot = lengthOfLL - (k % lengthOfLL);
        }
        else
        {
            pivot = lengthOfLL - k;
        }

        ListNode *newHead = head;
        newHead = rotateList(newHead, pivot);

        return newHead;
    }
};
