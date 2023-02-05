class Solution
{
public:
    int intersectPoint(Node* head1, Node* head2)
    {
        Node* ptr1 = head1;
        Node* ptr2 = head2;
        if(ptr1 == NULL || ptr2 == NULL)
            return -1;
        while(ptr1 != ptr2){
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
            
            //they meet at intersection point
            if(ptr1 == ptr2)
                return ptr1->data;
                
            //redirect ptr1 to second list head
            if(ptr1 == NULL)
                ptr1 = head2;
            //redirect ptr2 to first list head
            if(ptr2 == NULL)
                ptr2 = head1;
        }
        return -1;
    }
};
