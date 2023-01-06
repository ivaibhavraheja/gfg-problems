class Solution {
  public:
    int checkRedundancy(string s) {
        stack<char> st;
        for(int i=0; i<s.length(); i++){
            char ch = s[i];
            if(ch=='(' || ch=='+' || ch=='-' || ch=='*' || ch=='/'){
                st.push(ch);
            }
            else{
                //ch ya to ')' hai ya lower case
                if(ch==')'){
                    bool isRedundant = true;
                    
                    while(st.top() != '('){
                        char top = st.top();
                        if( top=='+' || top=='-' || top=='*' || top=='/'){
                            isRedundant = false;
                        }
                        st.pop();
                    }
                    
                    if(isRedundant == true){
                        return 1;
                    }
                    st.pop();
                }
            }
        }
        return 0;
    }
};
