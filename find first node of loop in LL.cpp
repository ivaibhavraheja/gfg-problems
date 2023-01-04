class Solution
{
    public:
    Node* detectLoop(Node* head){
        if(head == NULL){
            return NULL;
        }
        Node* slow = head;
        Node* fast = head;
        while(fast != NULL && slow != NULL){
            fast = fast->next;
            if(fast != NULL){
                fast = fast->next;
            }
            slow = slow->next;
            if(fast == slow){
                return slow;
            }
        }
        return NULL;
    }
    int findFirstNode(Node* head)
    {
        if(head == NULL){
            return NULL;
        }
        Node* loop = detectLoop(head);
        if(loop == NULL){
            return -1;
        }
        Node* slow = head;
        while(slow != loop){
            slow = slow->next;
            loop = loop->next;
        }
        return slow->data;
    }
};
