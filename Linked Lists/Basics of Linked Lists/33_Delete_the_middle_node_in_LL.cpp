
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
    int sizeofLL(ListNode *head)
    {
        ListNode *curr = head;
        int cnt = 0;

        while (curr != nullptr)
        {
            cnt++;
            curr = curr->next;
        }

        return cnt;
    }

public:
    ListNode *deleteMiddle(ListNode *head)
    {

        int length = sizeofLL(head);
        if (length == 1)
            return nullptr;
        int mid = length / 2;

        ListNode *curr = head;

        while (curr != nullptr)
        {

            if (mid == 1)
            {
                curr->next = curr->next->next;
                break;
            }
            mid--;
            curr = curr->next;
        }
        return head;
    }
}

// Optimal soln (T.C - O(n/2), S.C - O(1))
class Solution
{
public:
    ListNode *deleteMiddle(ListNode *head)
    {

        if (head == nullptr || head->next == nullptr)
            return nullptr;

        ListNode *slow = head;
        ListNode *fast = head->next;

        while (fast != nullptr && fast->next != nullptr && fast->next->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        slow->next = slow->next->next;
        return head;
    }
};