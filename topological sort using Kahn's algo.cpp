#include <bits/stdc++.h> 
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e){
    //create adjacency list
    unordered_map<int, list<int>> adj;
    for(int i=0; i<edges.size(); i++){
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
    }

    //find indegree of all nodes
    vector<int> indegree(v);
    for(auto i : adj){
        for(auto j : i.second){
            indegree[j]++;
        }
    }

    //create queue and push elements with 0 indegree in it
    queue<int> q;
    for(int i=0; i<v; i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }

    vector<int> ans;

    //traverse the adj list and call bfs
    while(!q.empty()){
        int front = q.front();
        q.pop();

        //ans store
        ans.push_back(front);

        //neighbour indegree update
        for(auto neighbour : adj[front]){
            indegree[neighbour]--;
            if(indegree[neighbour] == 0)
                q.push(neighbour);
        }
    }

    return ans;
}
