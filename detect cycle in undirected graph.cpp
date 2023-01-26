class Solution {
  private:
    bool isCyclicDFS(int node, int parent, unordered_map<int, bool> &visited, vector<int> adj[]){
        visited[node] = true;
        for(auto neighbour : adj[node]){
            if(!visited[neighbour]){
                bool cycleDetected = isCyclicDFS(neighbour, node, visited, adj);
                if(cycleDetected)
                    return true;
            }
            else if(neighbour != parent)
                return true;
        }
        return false;
    }
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        unordered_map<int, bool> visited;
        for(int i=0; i<V; i++){
            if(!visited[i]){
                bool ans = isCyclicDFS(i, -1, visited, adj);
                if(ans == 1)
                    return true;
            }
        }
        return false;
    }
};
