class Solution {
  private:
    void dfs(int node, unordered_map<int, bool> &visited, stack<int> &s, unordered_map<int, list<pair<int, int>> > adj){
        visited[node] = true;
        for(auto neighbour : adj[node]){
            if(!visited[neighbour.first]){
                dfs(neighbour.first, visited, s, adj);
            }
        }
        s.push(node);
    }
    
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        //create adjacency list
        unordered_map<int, list<pair<int, int>> > adj;
        for(int i=0; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int d = edges[i][2];
            pair<int, int> p = make_pair(v, d);
            adj[u].push_back(p);
        }
        
        //topological sort
        unordered_map<int, bool> visited;
        stack<int> s;
        for(int i=0; i<N; i++){
            if(!visited[i]){
                dfs(i, visited, s, adj);
            }
        }
        
        //update distance in array for each element in stack
        vector<int> dist(N);
        for(int i=0; i<N; i++){
            dist[i] = INT_MAX;
        }
        dist[0] = 0;
        while(!s.empty()){
            int top = s.top();
            s.pop();
            
            if(dist[top] != INT_MAX){
                for(auto i: adj[top]){
                    if(dist[top] + i.second < dist[i.first]){
                        dist[i.first] = dist[top] + i.second; 
                    }
                }
            }
        }
        
        for(int i=0; i<N; i++){
            if(dist[i] == INT_MAX)
                dist[i] = -1;
        }
        
        return dist;
    }
};
