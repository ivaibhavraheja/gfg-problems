class Solution {
  public:
    int solve(Node* root, unordered_map<Node*, int> &map){
        if(root==NULL){
            return 0;
        }
        map[root] = solve(root->left, map) + solve(root->right, map) + root->data;
        return map[root];
    }
    
    int findLargestSubtreeSum(Node* root)
    {
        unordered_map<Node* , int> map;
        solve(root, map);
        int ans = INT_MIN;
        for(auto i:map){
            ans = max(ans, i.second);
        }
        return ans;
    }
};
