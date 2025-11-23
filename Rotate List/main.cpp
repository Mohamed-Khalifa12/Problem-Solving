ListNode* rotateRight(ListNode* head, int k) {
    //check the size of the list
    if(head == nullptr)
        return nullptr;

    if(head->next == nullptr)
        return head;

    int listSize = getSize(head);
    for(int i = 0; i < k%listSize; i++)
    {
        ListNode* prevLast = getPrevLast(head);
        ListNode* last = prevLast->next;

        prevLast->next = nullptr;
        last->next = head;
        head = last;
    }

    return head;
}


ListNode* getPrevLast(ListNode* head)
{
    if(head == nullptr)
        return nullptr;

    if(head->next == nullptr)
        return head;
    
    while(head->next != nullptr)
    {
        if(head->next->next == nullptr)
            return head;
        head = head->next;
    }

    return nullptr;
}

int getSize(ListNode* head)
{
    int count = 0;
    while(head != nullptr)
    {
        count++;
        head = head->next;
    }

    return count;
}