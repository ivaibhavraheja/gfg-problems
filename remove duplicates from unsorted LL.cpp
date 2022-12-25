class Solution
{
    public:
    //Function to remove duplicates from unsorted linked list.
    Node * removeDuplicates( Node *head) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        Node* curr = head;
        Node* prev = NULL;
        unordered_map<int, bool> visited;
    
        while(curr != NULL){
            if(visited.find(curr->data) == visited.end()){  
                //data not found in map
                visited.emplace(curr->data, true);
                prev = curr;
                curr = curr->next;
            }
            else if(visited[curr->data] == true){
                //element found in map
                prev ->next = curr->next;
                curr = curr->next;
            }
        }
        return head;
    }
};
