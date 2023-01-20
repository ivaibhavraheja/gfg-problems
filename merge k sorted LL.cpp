class compare{
  public:
    bool operator()(Node* a,Node* b){
        return (a->data > b->data);
    }
};

class Solution{
  public:
    //Function to merge K sorted linked list.
    Node * mergeKLists(Node *arr[], int K)
    {
        priority_queue<Node*, vector<Node*>, compare> minHeap;
           
        for(int i=0; i<K; i++){
            if(arr[i] != NULL){
               minHeap.push(arr[i]);
           }
       }
           
        Node* head = NULL;
        Node* tail = NULL;
        while(!minHeap.empty()){
            Node* temp = minHeap.top();
            minHeap.pop();
            if(temp->next != NULL){
                minHeap.push(temp->next);
            }
               
            if(head == NULL){
                head = temp;
                tail = temp;
            }
            else{
                tail->next = temp;
                tail = temp;
            }
            
        }
        return head;
    }
};
