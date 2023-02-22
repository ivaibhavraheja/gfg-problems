class Solution{
    public:
    void connect(Node *root)
    {
       queue<Node*> q;
       if(root == NULL){
           return;
       }
       q.push(root);
       //using level order traversal
       while(!q.empty()){
           Node* prev = NULL;
           int n = q.size();
           while(n--){
               Node* temp = q.front();
               q.pop();
               if(prev != NULL){
                   prev->nextRight = temp;
               }
               if(temp->left){
                   q.push(temp->left);
               }
               if(temp->right){
                   q.push(temp->right);
               }
               prev = temp;
           }
       }
       
    }    
};
