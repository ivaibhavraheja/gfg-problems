vector<long long> printFirstNegativeInteger(long long int A[], long long int N, long long int K) {
    deque<long long> dq;
    vector<long long> ans;
    
    //process first window
    for(long long i=0; i<K; i++){
        if(A[i] < 0){
            dq.push_back(i);
        }
    }
    
    //push answer for first window
    if(dq.size() > 0){
        ans.push_back(A[dq.front()]);
    }
    else{
        ans.push_back(0);
    }
    
    //process for remaining windows
    for(long long i=K; i<N; i++){
        //removal
        if(i - dq.front() >= K && !dq.empty()){
            dq.pop_front();
        }
        //addition
        if(A[i] < 0){
            dq.push_back(i);
        }
        ///answer store
        if(dq.size() > 0){
            ans.push_back(A[dq.front()]);
        }
        else{
            ans.push_back(0);
        }
    }
    return ans;
 }
