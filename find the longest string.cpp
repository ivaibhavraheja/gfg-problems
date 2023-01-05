class Solution
{
public:
    string longestString(vector<string> &words)
    {
        //sort the array of strings
        sort(words.begin(), words.end());
        
        //making a map for keeping track of all the strings present and mark them 1
        unordered_map<string, int>mp;
        for(auto it:words){
            mp[it] = 1;
        }
        
        //maintaining a temporary answer string
        string ans = "";
        int size = INT_MIN;
        
        //traversing the array get the largest string
        for(auto i : words){
            //making a temporary string
            string temp;
            int c=0, n=i.size();
            for(int j=0; j<n; j++){
                temp = temp + i[j];
                if(mp[temp]){   //if word is present in map
                    c++;
                }
            }
            if(c==n && n>size){       //dont update if size of string is same as ans 
                size = n;
                ans = i;
            }
        }
        return ans;
    }
};
