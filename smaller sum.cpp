class Solution{
public:
    vector<long long> smallerSum(int n,vector<int> &arr){
        vector<long long> ans;
        
        //creating another array same as given 
        vector<int> v = arr;
        //sort it to get numbers smaller than a number
        sort(v.begin(), v.end());
        unordered_map<long long, long long> mp;
        
        long long sum = 0;
        for(int i=0; i<n; i++){
            mp.insert({v[i], sum});
            sum = sum + v[i];
        }
        
        for(int i=0; i<n; i++){
            ans.push_back(mp[arr[i]]);
        }
        
        return ans;
    }
};
