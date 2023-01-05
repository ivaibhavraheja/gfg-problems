class Solution{
private:
    void insertAtBottom(stack<int> &stack, int x){
        if(stack.empty()){
            stack.push(x);
            return;
        }
        int num = stack.top();
        stack.pop();
        
        insertAtBottom(stack, x);
        
        stack.push(num);
    }
public:
    void Reverse(stack<int> &St){
        //base case
        if(St.empty()){
            return;
        }
        
        int num = St.top();
        St.pop();
        
        //recursive call
        Reverse(St);
        
        insertAtBottom(St, num);
    }
};
