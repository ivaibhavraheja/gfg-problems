void solve(Node* root, vector<vector<int>> &ans, vector<int> temp){
    //base case
    if(root == NULL)
        return;
    if(root->left == NULL && root->right == NULL){
        temp.push_back(root->data);
        ans.push_back(temp);
        return;
    }
    
    temp.push_back(root->data);
    solve(root->left, ans, temp);
    solve(root->right, ans, temp);
    
    //backtrack
    temp.pop_back();
}

vector<vector<int>> Paths(Node* root)
{
    vector<vector<int>> ans;
    vector<int> temp;
    solve(root, ans, temp);
    return ans;
}
