class Solution{
  public:
  long long int wineSelling(vector<int>& Arr, int N){
      long long int sum = 0;
      vector<pair<int, int>> p;
      vector<pair<int, int>> n;
      for(int i=0; i<N; i++){
          if(Arr[i] > 0){
              p.push_back(make_pair(Arr[i], i));
          }
          if(Arr[i] < 0){
              n.push_back(make_pair(Arr[i], i));
          }
      }
      int k = 0;
      for(int i=0; i<p.size(); i++){
          for(int j=k; j<n.size(); j++){
              if(p[i].first > 0){
                  if(-1*n[j].first < p[i].first){
                      p[i].first += n[j].first;
                      sum += -1*n[j].first*abs(p[i].second - n[j].second);
                      n[j].first = 0;
                      k++;
                  }
                  else{
                      n[j].first += p[i].first;
                      sum += p[i].first * abs(p[i].second - n[j].second);
                      p[i].first = 0;
                  }
              }
              else{
                  break;
              }
          }
      }
      return sum;
  }
};
