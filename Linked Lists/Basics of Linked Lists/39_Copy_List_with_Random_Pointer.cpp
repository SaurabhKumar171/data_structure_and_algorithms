// Brute force (T.C - {O(N)}, S.C -{O(N) + O(N)})
class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        Node *curr = head;

        unordered_map<Node *, Node *> mp;

        while (curr != nullptr)
        {
            Node *newNode = new Node(curr->val);
            mp[curr] = newNode;
            curr = curr->next;
        }

        curr = head;
        while (curr != nullptr)
        {
            Node *copyNode = mp[curr];

            copyNode->next = mp[curr->next];
            copyNode->random = mp[curr->random];

            curr = curr->next;
        }

        return mp[head];
    }
};

// Optimal Soln (T.C - { O(N)}, S.C - O(N))
class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        if (!head)
            return nullptr;

        // Step 1: Create a copy of each node and insert it right after the original node.
        Node *curr = head;
        while (curr != nullptr)
        {
            Node *newNode = new Node(curr->val);
            newNode->next = curr->next;
            curr->next = newNode;
            curr = newNode->next;
        }

        // Step 2: Assign random pointers for the copied nodes.
        curr = head;
        while (curr != nullptr)
        {
            if (curr->random != nullptr)
            {
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next;
        }

        // Step 3: Separate the copied list from the original list.
        curr = head;
        Node *dummyNode = new Node(-1);
        Node *copyCurr = dummyNode;

        while (curr != nullptr)
        {
            copyCurr->next = curr->next;
            curr->next = curr->next->next;
            curr = curr->next;
            copyCurr = copyCurr->next;
        }

        return dummyNode->next;
    }
};