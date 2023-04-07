class Solution{   
public:
    int addMinChar(string str){    
        int count = 0;
        int i = 0;
        int j = str.length() - 1;
        while(i < j){
            if(str[i] == str[j]){
                i++;
                j--;
            }
            else{
                count++;
                //to get back to start because character may have repeated but string may not be palindrome
                i = 0;
                j = str.length() - 1- count;
            }
        }
        return count;
    }
};
