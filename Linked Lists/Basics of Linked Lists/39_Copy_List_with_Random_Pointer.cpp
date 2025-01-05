// Brute force (T.C - {O(N)}, S.C -{O(N)})
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