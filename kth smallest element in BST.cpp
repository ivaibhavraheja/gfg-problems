class Solution {
        
  public:
    int solve(Node* root, int K, int& i){
            //base case
            if(root==NULL){
                return -1;
            }
            
            int left = solve(root->left, K, i);
            if(left != -1){
                return left;
            }
            i++;
            
            if(i == K){
                return root->data;
            }
            
            return solve(root->right, K, i);
        }
    // Return the Kth smallest element in the given BST
    int KthSmallestElement(Node *root, int K) {
       int i = 0;
       solve(root, K, i);
    }
};
