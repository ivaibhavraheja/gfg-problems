class Solution{
public:
    int goodStones(int n,vector<int> &arr){
        vector<bool> visited(n, false);
        set<int> s;
        vector<int> temp;
        for(int i=0; i<n; i++){
            if(visited[i])
                continue;
            int j = i;
            while(!visited[j]){
                visited[j] = true;
                temp.push_back(j);
                j = j + arr[j];
                if(j >= n || j < 0){
                    for(auto k : temp){
                        s.insert(k);
                    }
                    temp.clear();
                    break;
                }
            }
            //check if there is any element in set ans can be used to move out
            if(temp.size() && s.count(j)){
                for(auto k: temp){
                    s.insert(k);
                }
            }
            //since it forms a loop remove the elements from temporary
            temp.clear();
        }
        return s.size();
    }  
};
