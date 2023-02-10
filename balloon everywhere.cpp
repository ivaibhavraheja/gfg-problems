class Solution{
public:
    int maxInstance(string s){
        vector<int> actual(26, 0);
        vector<int> given(26, 0);
        string k = "balloon";
        for(int i=0; i<k.length(); i++){
            actual[k[i] - 'a']++;
        }
        
        for(int i=0; i<s.length(); i++){
            given[s[i] - 'a']++;
        }
        
        int mini = INT_MAX;
        for(int i=0; i<actual.size(); i++){
            int r;
            if(actual[i]!=0 && given[i]!=0){
                r = given[i]/actual[i];
            }
            mini = min(mini, r);
        }
        return mini;
    }
};
