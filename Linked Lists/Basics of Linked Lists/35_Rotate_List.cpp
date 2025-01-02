
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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