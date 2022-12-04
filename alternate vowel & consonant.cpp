class Solution{
    public:
    void util(vector<int> &a, vector<int> &b, string &s){
        int p=0, q=0;
        for(int i=0; i<s.length(); i++){
            if(i%2==0){
                while(a[p]==0){
                    p++;
                }
                s[i] = p + 'a';
                a[p]--;
            }
            else{
                while(b[q]==0)
                    q++;
                s[i] = q + 'a';
                b[q]--;
            }
        }
    }
    string rearrange (string S, int N)
    {
        //make array for storing frequency of each vowel and consonant 
        vector<int> v(26, 0), c(26, 0);
        int v_count = 0;
        for(auto x:S){
            if(x=='a' || x=='e' || x=='i' || x=='o' || x=='u'){
                v_count++;
                v[x-'a']++;    //store frequency at the respective position e.g -> e at v[4] , a at v[0]
            }
            else{
                c[x-'a']++;
            }
        }
        
        int c_count = N - v_count;
        if(abs(c_count - v_count) > 1)
            return "-1";
            
        if(v_count > c_count){
            util(v, c, S);
        }
        else if(v_count < c_count){
            util(c, v, S);
        }
        else{    //both are equal in number
            for(int i=0; i<26; i++){
                //if first consonant is smaller than first vowel
                if(c[i] > 0){
                    util(c, v, S);
                }
                //if first vowel is smaller than first consonant
                if(v[i] > 0){
                    util(v, c, S);
                }
            }
            
        }
        return S;
    }
    
};
