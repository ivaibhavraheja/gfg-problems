class Solution {
  public:
    long long solve(int N, int K, vector<long long> GeekNum) {
        queue<long long> q;
        long long nextNum = 0;
        for(int i=0; i<K; i++){
            q.push(GeekNum[i]);
            nextNum += GeekNum[i];
        }
        
        int size = q.size();
        for(int i=0; i<N-K; i++){
            long long front = q.front();
            q.pop();
            q.push(nextNum);
            nextNum = nextNum*2;
            nextNum = nextNum - front;
        }
        long long ans;
        while(!q.empty()){
            ans = q.front();
            q.pop();
        }
        return ans;
    }
};
