#include <bits/stdc++.h> 
void interLeaveQueue(queue<int> &q){
    int n = q.size();
    stack<int> s;
    //step 1
    for(int i=0; i<n/2; i++){
        s.push(q.front());
        q.pop();
    }
    //step 2
    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }
    //step 3
    for(int i=0; i<n/2; i++){
        q.push(q.front());
        q.pop();
    }
    //step 4
    for(int i=0; i<n/2; i++){
        s.push(q.front());
        q.pop();
    }
    //step 5
    while(!s.empty()){
        q.push(s.top());
        s.pop();
        q.push(q.front());
        q.pop();
    }
}
