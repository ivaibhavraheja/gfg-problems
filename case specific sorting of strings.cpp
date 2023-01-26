class Solution
{
    public:
    //Function to perform case-specific sorting of strings.
    string caseSort(string str, int n)
    {
        string duplicate = str;
        vector<int> lower;
        vector<int> upper;
        for(int i=0; i<str.length(); i++){
            if(str[i] >= 'a' && str[i] <= 'z')
                lower.push_back(i);
            else
                upper.push_back(i);
        }
        sort(duplicate.begin(), duplicate.end());
        int i=0; 
        while(i < upper.size()){
            str[upper[i]] = duplicate[i];
            i++;
        }
        
        int j = 0;
        while(j < lower.size()){
            str[lower[j]] = duplicate[i];
            j++;
            i++;
        }
        
        return str;
    }
};
