
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// Brute force (T.C - O(2n), S.C - O(1))

class Solution
{
private:
    ListNode *getKthNode(ListNode *curr, int k)
    {
        k -= 1;
        while (k > 0 && curr != nullptr)
        {
            k--;
            curr = curr->next;
        }

        return curr;
    }

    ListNode *reverseLL(ListNode *head)
    {
        ListNode *curr = head;
        ListNode *prev = nullptr;

        while (curr != nullptr)
        {
            ListNode *nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        return prev;
    }

public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        ListNode *temp = head;
        ListNode *prevNode = nullptr;

        while (temp != nullptr)
        {
            ListNode *kThNode = getKthNode(temp, k);

            if (kThNode == nullptr)
            {
                if (prevNode)
                    prevNode->next = temp;

                break;
            }

            ListNode *nextNode = kThNode->next;
            kThNode->next = nullptr;

            reverseLL(temp);

            if (temp == head)
            {
                head = kThNode;
            }
            else
            {
                prevNode->next = kThNode;
            }

            prevNode = temp;
            temp = nextNode;
        }

        return head;
    }
};