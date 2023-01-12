class Solution {
	public:
		string FirstNonRepeating(string A){
		    unordered_map<char, int> count;
		    string ans = "";
		    queue<char> q;
		    
		    for(int i=0; i<A.length(); i++){
		        char ch = A[i];
		        
		        //count increase
		        count[ch]++;
		        
		        //push in queue
		        q.push(ch);
		        
		        while(!q.empty()){
		            if(count[q.front()] > 1){     //repeating character
		                q.pop();
		            }
		            else{                         //non-repeating character
		                ans.push_back(q.front());
		                break;
		            }
		        }
		        if(q.empty()){
		            ans.push_back('#');
		        }
		    }
		    return ans;
		}
};
