string buildLowestNumber(string num, int k)
{
    //we start from beginning and check whether previous number of a number is smaller or larger than it. 
    //if previous is smaller then store current number else delete previous number
    stack<char> st;
    st.push(num[0]);
    for(int i=1; i<num.length(); i++){
        while(k>0 && st.empty()==false && st.top()-'0' > num[i]-'0'){
            //if previous number is greater
            st.pop();
            k--;
        }
        st.push(num[i]);
    }
    //if required number of elements are not deleted i.e. less than k
    while(k > 0){
        st.pop();
        k--;
    }
    
    //store the remaining in string
    string ans = "";
    while(!st.empty()){
        ans = st.top() + ans;
        st.pop();
    }
    
    int lz = -1;
    for(int i=0; i<ans.length(); i++){
        if(ans[i] != '0')
            break;
        lz = i;     //store the index up to which leading zeroes are present
    }
    
    if(lz == ans.length()-1){
        return "0";
    }
    if(lz >= 0){
        //return from index after leading zeroes
        return ans.substr(lz + 1);
    }
    return ans;
}
