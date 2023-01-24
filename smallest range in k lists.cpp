class node{
    public:
    int data;
    int row;
    int col;
    node(int d, int r, int c){
        data = d;
        row = r;
        col = c;
    }
};

class compare{
    public:
    bool operator()(node* a, node* b){
        return a->data > b->data;
    }
};

class Solution{
    public:
    pair<int,int> findSmallestRange(int KSortedArray[][N], int n, int k)
    {
          priority_queue<node*, vector<node*>, compare> minHeap;
          int mini = INT_MAX, maxi = INT_MIN;
      
          //step1: create a minHeap for storing element of each List and tracking min/max element
          for(int i=0; i<k; i++){
              int element = KSortedArray[i][0];
              mini = min(mini, element);
              maxi = max(maxi, element);
              minHeap.push(new node(element, i, 0));
          }
          
          int start = mini, end = maxi;
          
          //process ranges
          while(!minHeap.empty()){
              node* temp = minHeap.top();
              minHeap.pop();
              
              int mini = temp->data;
              
              if(maxi - mini < end - start){
                  start = mini;
                  end = maxi;
              }
              
              //next element exists or not
              if(temp->col + 1 < n){
                  maxi = max(maxi, KSortedArray[temp->row][temp->col + 1]);
                  minHeap.push(new node(KSortedArray[temp->row][temp->col + 1], temp->row, temp->col+1));
              }
              else{
                  break;
              }
          }
          pair<int, int> p = make_pair(start, end);
          return p;
    }
};
