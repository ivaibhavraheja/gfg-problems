class Solution{
public:	
	// Converts arr[0..n-1] to reduced form.
	void convert(int arr[], int n) {
	    unordered_map<int, int> originalToNew;
	    vector<int> nw(n);
	    for(int i=0; i<n; i++){
	        nw[i] = arr[i];
	    }
	    sort(nw.begin(), nw.end());
	    for(int i=0; i<n; i++){
	        originalToNew[nw[i]] = i;
	    }
	    
	    for(int i=0; i<n; i++){
	        arr[i] = originalToNew[arr[i]];
	    }
	}
};
