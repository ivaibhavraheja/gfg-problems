class Solution {
  public:
    vector<int> maximumValue(Node* node) {
        vector<int> ans;
        queue<Node*> q;
        q.push(node);
        q.push(NULL);
        int maxi = INT_MIN;
        while(!q.empty()){
            Node* temp = q.front();
            q.pop();
            if(temp == NULL){
                ans.push_back(maxi);
                maxi = INT_MIN;
                if(!q.empty()){       //queue still has some child nodes
                    q.push(NULL);
                }
            }
            else{
                maxi = max(maxi, temp->data);
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
            }
        }
        return ans;
    }
};
