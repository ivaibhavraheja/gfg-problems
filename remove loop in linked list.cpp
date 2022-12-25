class Solution
{
    public:
    Node* floydLoopDetect(Node* head){
        if(head == NULL){
            return NULL;
        }
        Node* slow = head;
        Node* fast = head;
        while(slow != NULL && fast != NULL){
            fast = fast -> next;
            if(fast != NULL){
                fast = fast->next;
            }
            slow = slow->next;
            if(slow == fast){
                return slow;
            }
        }
        return NULL;
    }
    
    Node* getStartingNode(Node* head){
        if(head == NULL){
            return NULL;
        }
        Node* intersection = floydLoopDetect(head);
        if(intersection == NULL){
            return NULL;
        }
        Node* slow = head;
        while(slow != intersection){
            slow = slow -> next;
            intersection = intersection -> next;
        }
        return slow;
    }
    //Function to remove a loop in the linked list.
    void removeLoop(Node* head)
    {
       if(head == NULL){
           return;
       }
       Node* startOfLoop = getStartingNode(head);
       if(startOfLoop == NULL){
           return ;
       }
       Node* temp = startOfLoop;
       while(temp->next != startOfLoop){
           temp = temp->next;
       }
       temp ->next = NULL;
    }
};
