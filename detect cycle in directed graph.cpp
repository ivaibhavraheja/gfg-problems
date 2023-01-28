class Solution {
  private:
    bool cyclicDFS(int node, unordered_map<int, bool> &visited, unordered_map<int, bool> &dfsVisited, vector<int> adj[]){
        visited[node] = true;
        dfsVisited[node] = true;
        for(auto neighbour : adj[node]){
            if(!visited[neighbour]){
                bool cyclic = cyclicDFS(neighbour, visited, dfsVisited, adj);
                if(cyclic)
                    return true;
            }
            else if(visited[neighbour] && dfsVisited[neighbour])
                return true;
        }
        dfsVisited[node] = false;
        return false;
    }
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        unordered_map<int, bool> visited;
        unordered_map<int, bool> dfsVisited;
        
        for(int i=0; i<V; i++){
            if(!visited[i]){
                bool ans = cyclicDFS(i, visited, dfsVisited, adj);
                if(ans)
                    return true;
            }
        }
        return false;
    }
};
