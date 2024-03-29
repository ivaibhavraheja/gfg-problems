queue<int> modifyQueue(queue<int> q, int k) {
    stack<int> st;
    for(int i=0; i<k; i++){
        st.push(q.front());
        q.pop();
    }
    while(!st.empty()){
        q.push(st.top());
        st.pop();
    }
    for(int i=0; i<q.size()-k; i++){
        int data = q.front();
        q.pop();
        q.push(data);
    }
    return q;
}
