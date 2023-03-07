class Solution{
  public:
    int maxLevelSum(Node* root) {
        if(root == NULL)
            return 0;
        queue<Node*> q;
        q.push(root);
        q.push(NULL);
        int maxsum = INT_MIN;
        int sum = 0;
        while(!q.empty()){
            Node* temp = q.front();
            q.pop();
            
            if(temp == NULL){
                maxsum = max(maxsum, sum);
                sum = 0;
                if(!q.empty()){
                    q.push(NULL);
                }
            }
            else{
                sum = sum + temp->data;
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
            }
        }
        return maxsum;
    }
};
