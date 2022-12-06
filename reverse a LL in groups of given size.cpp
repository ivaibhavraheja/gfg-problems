class Solution
{
    public:
    struct node *reverse (struct node *head, int k)
    { 
        //base case
        if(head == NULL){
            return NULL;
        }
        
        //step1
        int count = 0;
        struct node* prev = NULL;
        struct node* next = NULL;
        struct node* curr = head;
        while(curr != NULL && count < k){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }
        
        //step2
        if(next != NULL){
            head -> next = reverse(next, k);
        }
        
        //step3
        return prev;
    }
};
