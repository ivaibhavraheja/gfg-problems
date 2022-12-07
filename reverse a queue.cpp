// void recur(queue<int> &q){
//     if(q.empty()){
//         return ;
//     }
//     int data = q.front();
//     q.pop();
//     q = rev(q);
//     q.push(data);
// }

queue<int> rev(queue<int> q)
{
    // recur(q);
    // return q;
    // add code here.
    stack<int> s;
    while(!(q.empty())){
        s.push(q.front());
        q.pop();
    }
    while(!(s.empty())){
        q.push(s.top());
        s.pop();
    }
    return q;
}
