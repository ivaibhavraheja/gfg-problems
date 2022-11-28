class Solution {
        
  public:
    int solve(Node* root, int K, int& i){
            //base case
            if(root==NULL){
                return -1;
            }
            
            //search in left Subtree
            int left = solve(root->left, K, i);
            
            //if element is found in leftSubtree then return 
            if(left != -1){
                return left;
            }
            i++;
            
            // if current element is k'th smallest, return it
            if(i == K){
                return root->data;
            }
            
            //else search in right Subtree
            return solve(root->right, K, i);
        }
    // Return the Kth smallest element in the given BST
    int KthSmallestElement(Node *root, int K) {
       int i = 0;
       solve(root, K, i);
    }
};
