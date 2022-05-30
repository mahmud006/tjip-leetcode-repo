class MyLinkedList
{
public:
    int DUMMYVALUE = INT_MIN;
    class LinkedListNode
    {
    public:
        int value;
        LinkedListNode *next;
        LinkedListNode(int val, LinkedListNode *nxt)
        {
            value = val;
            next = nxt;
        }
    };

private:
    LinkedListNode *head;
    int len;

public:
    MyLinkedList()
    {
        len = 0;
        head = new LinkedListNode(DUMMYVALUE, NULL);
    }

    int get(int index)
    {
        if (index < 0 || index >= len)
            return -1;
        auto curr = head->next;
        while (index--)
        {
            curr = curr->next;
        }
        return curr->value;
    }

    void addAtHead(int val)
    {
        addAtIndex(0, val);
    }

    void addAtTail(int val)
    {
        addAtIndex(len, val);
    }

    void addAtIndex(int index, int val)
    {
        if (index < 0 || index > len)
            return;
        auto curr = head;
        while (index--)
        {
            curr = curr->next;
        }
        auto jointNode = curr->next;
        curr->next = new LinkedListNode(val, NULL);
        curr->next->next = jointNode;
        len++;
    }

    void deleteAtIndex(int index)
    {
        if (index < 0 || index >= len)
            return;
        auto curr = head;
        while (index--)
        {
            curr = curr->next;
        }
        auto dumpNode = curr->next;
        curr->next = curr->next->next;
        delete (dumpNode);
        len--;
    }
};