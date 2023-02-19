class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        vector<int> dist(V, INT_MAX);
        
        //making a priority queue (minHeap) to get the node with minimum distance
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
        dist[S] = 0;
        pq.push({0, S});
        
        while(!pq.empty()){
            //get node and distance of the topNode of queue
            int node = pq.top().second;
            int distance = pq.top().first;
            
            //remove from queue
            pq.pop();
            
            for(auto neighbour : adj[node]){
                int adj_node = neighbour[0];
                int weight = neighbour[1];
                
                if(weight + distance < dist[adj_node]){
                    dist[adj_node] = weight + distance;
                    pq.push({dist[adj_node], adj_node});
                }
            }
        }
        return dist;
    }
};
