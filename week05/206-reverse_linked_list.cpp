// TC - O(n)
// MC - O(n)
// n = number of nodes
class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *prv = NULL;
        auto curr = head;
        while (curr)
        {
            auto next = curr->next;
            curr->next = prv;
            prv = curr;
            curr = next;
        }
        return prv;
    }
};