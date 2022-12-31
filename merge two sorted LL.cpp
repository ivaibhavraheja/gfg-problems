Node* solve(Node* first, Node* second){
    //if only one element is present in first linked list
    if(first->next == NULL){
        first->next = second;
        return first;
    }
    Node* curr1 = first;
    Node* next1 = curr1->next;
    Node* curr2 = second;
    Node* next2 = curr2->next;
    while(next1 != NULL && curr2 != NULL){
        if((curr2->data >= curr1->data) && (curr2->data <= next1->data)){
            //addition of nodes to first linked list
            curr1->next = curr2;
            next2 = curr2->next;
            curr2->next = next1;
            //updation of pointers
            curr1 = curr2;
            curr2 = next2;
        }
        else{
            //curr1 aur next1 pointers ko aage badhana hai
            curr1 = next1;
            next1 = next1->next;
            //1st list ends
            if(next1 == NULL){
                curr1->next = curr2;
                return first;
            }
        }
    }
    return first;
}

Node* sortedMerge(Node* head1, Node* head2)  
{  
    if(head1 == NULL)
        return head2;
    if(head2 == NULL)
        return head1;
    if(head1->data < head2->data)
        return solve(head1, head2);
    else
        return solve(head2, head1);
}  
