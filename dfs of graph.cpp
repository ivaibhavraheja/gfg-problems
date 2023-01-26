class Solution {
  public:
    void dfs(int V, vector<int>adj[],int i,vector<bool>&vis,vector<int>&ans){
        vis[i]=true;
        ans.push_back(i);
        for(auto x:adj[i]){
            if(!vis[x]) dfs(V,adj,x,vis,ans);
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<bool>vis(V,false);
        vector<int>ans;
        for(int i=0;i<V;i++){
            if(!vis[i]) 
                dfs(V,adj,i,vis,ans);
        }
        return ans;        
    }
};
