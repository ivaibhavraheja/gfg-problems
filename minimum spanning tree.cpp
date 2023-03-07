class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        //create min heap
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
        pq.push({0, 0});
        vector<bool> mst(V, false);
        int ans = 0;
        while(!pq.empty()){
            auto p = pq.top();
            pq.pop();
            int node = p.second;
            int weight = p.first;
            
            //node already present in the mst 
            if(mst[node])
                continue;
            else{
                mst[node] = true;
                ans = ans + weight;
                for(auto it : adj[node]){
                    if(!mst[it[0]]){
                        //at first index is the weight and zero index is the vertex
                        pq.push({it[1], it[0]});
                        //min heap automatically gets min weight edge at top
                    }
                }
            }
        }
        return ans;
    }
};
