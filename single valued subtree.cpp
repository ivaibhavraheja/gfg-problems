class Solution
{
    public:
    int ans = 0;
    pair<int, bool> subTree(Node* root){
        if(root == NULL){
            return {INT_MAX, true};
        }
        pair<int, bool> left = subTree(root->left);
        pair<int, bool> right = subTree(root->right);
        
        if(left.second && right.second){
            if((root->data==left.first || left.first==INT_MAX) && (root->data==right.first || right.first==INT_MAX)){
                ans++;
                return {root->data, true};
            }
        }
        return {root->data, false};
    }
    
    int singlevalued(Node *root)
    {
        pair<int, bool> temp = subTree(root);
        return ans;
    }
    
};
