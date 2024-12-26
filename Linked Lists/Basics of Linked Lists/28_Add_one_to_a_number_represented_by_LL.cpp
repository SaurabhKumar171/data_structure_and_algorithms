
// Brute force [T.C - 0(n), S.C - 0(1)]
class Solution
{
private:
    ListNode *reverseLL(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return head;

        ListNode *prev = nullptr;
        ListNode *curr = head;

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
    ListNode *addOne(ListNode *head)
    {

        ListNode *newHead = reverseLL(head);

        ListNode *curr = newHead;
        int carry = 1;

        ListNode *dummyNode = newHead;
        ListNode *prev = nullptr;

        while (curr != nullptr)
        {
            int sum = curr->val + carry;
            int tensPlace = sum % 10;
            carry = sum / 10;

            curr->val = tensPlace;
            prev = curr;
            curr = curr->next;
        }

        if (carry > 0)
        {
            ListNode *newNode = new ListNode(carry);
            prev->next = newNode;
        }

        newHead = reverseLL(dummyNode);

        return newHead;
    }
};

// Optimal solution [T.C - 0(n), S.C - 0(n) : due to recursion call stack]
class Solution
{
private:
    int helper(Node *temp)
    {
        if (temp == nullptr)
            return 1;

        int carry = helper(temp->next);

        temp->data = temp->data + carry;

        if (temp->data < 10)
        {
            return 0;
        }

        temp->data = temp->data % 10;

        return 1;
    }

public:
    Node *addOne(Node *head)
    {
        int carry = helper(head);

        if (carry == 1)
        {
            Node *newNode = new Node(carry);
            newNode->next = head;
            return newNode;
        }

        return head;
    }
};