class Solution{
  public:
    void solve(Node* root, int k, int &count, vector<int> path){
        //base case
        if(root == NULL){
            return;
        }
        
        //vector me current node push krte jao
        path.push_back(root->data);
        
        //left
        solve(root->left, k, count, path);
        //right
        solve(root->right, k, count, path);
        
        //check k sum
        int size = path.size();
        int sum = 0;
        for(int i=size-1; i>=0; i--){
            sum = sum + path[i];
            if(sum == k)
                count++;
        }
        path.pop_back();
    }
    
    int sumK(Node *root,int k)
    {
        vector<int> path;
        int count=0;
        solve(root, k, count, path);
        return count;
    }
