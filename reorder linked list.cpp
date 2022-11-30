class Solution{ 
public:
    Node* reverse(Node* head){
            Node* prev = NULL;
            Node* curr = head;
            Node* nxt = NULL;
            while(curr){
                nxt = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nxt;
            }
            return prev;
        }
    void reorderList(Node* head) {
        //step 1- using fast and slow pointer
        Node* slow = head;
        Node* fast = head->next;
        
        while(fast && fast->next){
            slow = slow -> next;         //takes slow pointer to mid of linked list
            fast = fast -> next ->next;
        }
        
        //step 2- split the list into two
        Node* list1 = head; //1 2 3
        Node* list2 = reverse(slow->next);  //4 5
        slow->next = NULL;
        
        //step3- merging the two list
        while(list2){
            Node* temp1 = list1->next;
            Node* temp2 = list2->next;
            list1->next = list2;
            list2->next = temp1;
            list1 = temp1;
            list2 = temp2;
        }
    }
};
