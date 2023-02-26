class Solution {
    //if size of a connected component is n then for good component(connected) each element should have n-1 elements in its adjacency list
  private:
    void dfs(vector<vector<int>> &adj, int i, vector<int> &vis, vector<int> &temp){
        temp.push_back(i);
        vis[i]++;
        
        for(auto it : adj[i]){
            if(!vis[it])
                dfs(adj, it, vis, temp);
        }
    }
  public:
    int findNumberOfGoodComponent(int V, vector<vector<int>>& adj) {
        int ans = 0;
        vector<int> vis(V+1, 0);
        for(int i=1; i<=V; i++){
            //store the vertices in component
            if(!vis[i]){
                vector<int> temp;
                dfs(adj, i, vis, temp);
                bool flag = false;
                //check for that particular component
                for(int i=0; i<temp.size(); i++){
                    if(adj[temp[i]].size() < temp.size()-1){
                        flag = true;
                        break;
                    }
                }
                if(flag == false)
                    ans++;
            }
            
        }
        return ans;
    }
};
