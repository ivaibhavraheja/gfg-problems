class Solution
{
    private:
    void topological(int node, vector<bool> &visited, stack<int> &s, vector<int> adj[]){
        visited[node] = 1;
        for(auto neighbour : adj[node]){
            if(!visited[neighbour]){
                topological(neighbour, visited, s, adj);
            }
        }
        s.push(node);
    }
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<bool> visited(V);
	    stack<int> s;
	    vector<int> ans;
	    for(int i=0; i<V; i++){
	        if(!visited[i]){
	            topological(i, visited, s, adj);
	        }
	    }
	    
	    while(!s.empty()){
	        ans.push_back(s.top());
	        s.pop();
	    }
	    return ans;
	}
};
