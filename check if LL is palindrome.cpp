class Solution{
  public:
    Node* getMid(Node* head){
        Node* slow = head;
        Node* fast = head->next;
        while(fast != NULL && fast->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
    Node* reverse(Node* head){
        Node* curr = head;
        Node* prev = NULL;
        Node* next = NULL;
        while(curr != NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        if(head == NULL || head->next == NULL){
            return true;
        }
        //step 1 : find middle
        Node* middle = getMid(head);
        
        //step 2 : reverese linked list after middle
        Node* temp = middle->next;
        middle->next = reverse(temp);
        
        //step 3 : compare both halves
        Node* head1 = head;
        Node* head2 = middle->next;
        while(head2 != NULL){
            if(head1->data != head2->data){
                return false;
            }
            head1 = head1->next;
            head2 = head2->next;
        }
        return true;
    }
};
