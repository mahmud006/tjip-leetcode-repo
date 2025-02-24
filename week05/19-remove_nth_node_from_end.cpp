// TC - O(n)
// MC - O(1)
// n = number of nodes

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        auto s = head;
        auto f = head;
        while (n--)
        {
            f = f->next;
        }

        if (!f)
            return head->next;
        while (f->next)
        {
            s = s->next;
            f = f->next;
        }
        s->next = s->next->next;
        return head;
    }
};