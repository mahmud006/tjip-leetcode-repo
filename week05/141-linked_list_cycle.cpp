// TC - O(n)
// MC - O(1)
// n = number of nodes
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        if (head == NULL)
            return false;
        auto s = head;
        auto f = head;
        while (f->next && f->next->next)
        {
            s = s->next;
            f = f->next->next;
            if (f == s)
                return true;
        }
        return false;
    }
};