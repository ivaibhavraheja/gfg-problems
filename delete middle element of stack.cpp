class Solution
{   
    private:
    void solve(stack<int> &s, int count, int sizeOfStack){
        //base case
        if(count == sizeOfStack/2){
            s.pop();
            return;
        }
        
        //save the top and then pop
        int num = s.top();
        s.pop();
        
        //recursive call
        solve(s, count+1, sizeOfStack);
        
        //push the popped element back in stack
        s.push(num);
    }
    public:
    //Function to delete middle element of a stack.
    void deleteMid(stack<int>&s, int sizeOfStack)
    {
        int count = 0;
        solve(s, count, sizeOfStack);
    }
};
