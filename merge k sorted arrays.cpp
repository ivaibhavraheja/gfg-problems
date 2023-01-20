class node{
    public:
        int data;
        int a;
        int b;
    node(int data, int row, int col){
        this->data = data;
        a = row;
        b = col;
    }
};

class compare{
    public:
        bool operator()(node* a, node* b){
            return a->data > b->data;
        }
};

class Solution
{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        priority_queue<node* , vector<node*> , compare> minHeap; 
        
        //step1: push first elements of all arrays in minHeap 
        for(int i=0; i<K; i++){
            node* temp = new node(arr[i][0], i, 0);
            minHeap.push(temp);
        }
        
        //step2: 
        vector<int> ans;
        while(!minHeap.empty()){
            node* temp = minHeap.top();
            ans.push_back(temp->data);
            minHeap.pop();
            
            int i = temp->a;
            int j = temp->b;
            
            if(j+1 < arr[i].size()){
                node* next = new node(arr[i][j+1], i, j+1);
                minHeap.push(next);
            }
        }
        return ans;
    }
};
