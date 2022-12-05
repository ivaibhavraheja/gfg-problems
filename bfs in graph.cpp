class Solution {
  public:
    
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<int> ans;
        vector<bool> visited(V, 0);
        queue<int> q;
        q.push(0);
        visited[0] = true;
        
        while(!q.empty()){
            int frontNode = q.front();
            q.pop();
            ans.push_back(frontNode);
            
            for(auto i:adj[frontNode]){
                if(!visited[i]){
                    q.push(i);
                    visited[i] = 1;
                }
            }
        }
        return ans;
    }
};
