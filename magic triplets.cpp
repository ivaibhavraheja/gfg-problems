class Solution{
	public:
	int countTriplets(vector<int>nums){
	    // Code here.
	    int ans = 0;
	    int n=nums.size();
	    for(int i=1; i<=n-2; i++){
	        int less=0, more=0;
	        
	        //for smaller element
	        for(int j=i-1; j>=0; j--){
	            if(nums[j]<nums[i]){
	                less++;
	            }
	        }
	        
	        //for greater element
	        for(int j=i+1; j<n; j++){
	            if(nums[j]>nums[i]){
	                more++;
	            }
	        }
	        ans = ans + (less*more);
	    }
        return ans;
	}
};
