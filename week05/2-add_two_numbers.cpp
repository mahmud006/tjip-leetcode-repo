// TC - O(n)
// MC - O(n)
class Solution
{
public:
    ListNode *l3 = new ListNode();
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        int chk = 0;
        auto curr = l3;
        while (l1 != NULL && l2 != NULL)
        {
            int s1 = 0;
            s1 = (l1->val) + (l2->val) + chk;
            chk = 0;
            if (s1 > 9)
            {
                curr->next = new ListNode(s1 % 10);
                curr = curr->next;
                chk = 1;
            }
            else
            {
                curr->next = new ListNode(s1);
                curr = curr->next;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        while (l1 != NULL)
        {
            int s1 = 0;
            s1 = (l1->val) + chk;
            chk = 0;
            if (s1 > 9)
            {
                curr->next = new ListNode(s1 % 10);
                curr = curr->next;
                chk = 1;
            }
            else
            {
                curr->next = new ListNode(s1);
                curr = curr->next;
            }
            l1 = l1->next;
        }
        while (l2 != NULL)
        {
            int s1 = 0;
            s1 = (l2->val) + chk;
            chk = 0;
            if (s1 > 9)
            {
                curr->next = new ListNode(s1 % 10);
                curr = curr->next;
                chk = 1;
            }
            else
            {
                curr->next = new ListNode(s1);
                curr = curr->next;
            }
            l2 = l2->next;
        }
        if (chk == 1)
        {
            curr->next = new ListNode(chk);
            curr = curr->next;
        }
        l3 = l3->next;
        return l3;
    }
};