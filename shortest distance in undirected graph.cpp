class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        //create adjacency list
        unordered_map<int, list<int>> adj;
        for(int i=0; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int> dist(N);
        for(int i=0; i<N; i++){
            dist[i] = INT_MAX;
        }
        
        //do bfs
        queue<int> q;
        dist[src] = 0;
        q.push(src);
      
        while(!q.empty()){
            int front = q.front();
            q.pop();
            
            for(auto i:adj[front]){
                if(dist[front] + 1 < dist[i]){
                    dist[i] = dist[front] + 1;
                    q.push(i);
                }
            }
        }
        
        //if any node distance is stil INT_MAX 
        for(int i=0; i<dist.size(); i++){
            if(dist[i] == INT_MAX){
                dist[i] = -1;
            }
        }
        return dist;
        

    }
};
