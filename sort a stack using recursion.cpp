void sortedInsert(stack<int> &s, int num){
    //base case
    if(s.empty() || (!s.empty() && s.top()<num)){
        s.push(num);
        return;
    }
    
    int n = s.top();
    s.pop();
    
    //recursive call
    sortedInsert(s, num);
    
    s.push(n);
}
void SortedStack :: sort()
{
   //base case
   if(s.empty()){
       return;
   }
   
   int num = s.top();
   s.pop();
   
   //recursive call
   sort();
   
   sortedInsert(s, num);
}
