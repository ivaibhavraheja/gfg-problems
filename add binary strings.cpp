class Solution{
public:	
//because of time complexity instead of adding element to the front of string, we will push_back to the string
//and reverse the string after all addition to get the correct answer
	string addBinary(string A, string B)
	{
	    string ans="";
	    int carry = 0;
	    int i = A.size()-1;
	    int j = B.size()-1;
	    while(i>=0 || j>=0){
	        int sum = 0;
	        if(i>=0){
	            sum += A[i]-'0';      //A[i]-'0' done for converting character in integer
	            i--;
	        }
	        if(j>=0){
	            sum += B[j]-'0';
	            j--;
	        }
	        sum = sum + carry;
	        
	        //add sum in ans
	        char temp = sum%2 + '0';    //converting integer to character for adding in string;
	        ans.push_back(temp);        //time complexity O(1);
	        
	        //update carry
	        carry = sum / 2;
	    }
	    if(carry==1){
	        ans = ans + '1';
	    }
	    reverse(ans.begin(), ans.end());
	    //for removing leading 0
	    int index = 0;
	    while(ans[index]=='0'){
	        index++;
	    }
	    return ans.substr(index);
	}
};
