void splitList(Node *head, Node **head1_ref, Node **head2_ref)
{
    Node* slow = head;
    Node* fast = head;
    while(fast->next != head){
        fast = fast -> next;
        if(fast->next != head){
            slow = slow->next;
            fast = fast->next;
        }
    }
    *head1_ref = head;
    *head2_ref = slow->next;
    fast->next = *head2_ref;
    slow->next = *head1_ref;
}
