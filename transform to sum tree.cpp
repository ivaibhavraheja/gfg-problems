class Solution {
  public:
  
    // Convert a given tree to a tree where every node contains sum of values of
    // nodes in left and right subtrees in the original tree
    int transform(Node* root){
        if(root == NULL){
            return 0;
        }
        int left = transform(root->left);
        int right = transform(root->right);
        
        int temp = left + right + root->data;
        root->data = left + right;
        
        return temp;
    }
    void toSumTree(Node *node)
    {
        if(node == NULL){
            return;
        }
        transform(node);
    }
};
