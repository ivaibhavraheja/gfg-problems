class Solution{
    public:
    // int findPosition(int in[], int element, int n){
    //     for(int i=0; i<n; i++){
    //         if(in[i] == element){
    //             return i;
    //         }
    //     }
    //     return -1;
    // }
    
    void createMapping(int in[], map<int, int> &nodeToIndex, int n){
        for(int i=0; i<n; i++){
            nodeToIndex[in[i]] = i;
        }
    }
    
    Node* solve(int in[], int pre[], int &index, int inOrderStart, int inOrderEnd, int n, map<int, int> &nodeToIndex){
        //base case
        if(index >= n || inOrderStart > inOrderEnd){
            return NULL;
        }
        
        //create root node for element
        int element = pre[index++];
        Node* root = new Node(element);
        
        //find element's index in inOrder
        // int position = findPosition(in, element, n);
        int position = nodeToIndex[element];
        
        //recurssive calls
        root->left = solve(in, pre, index, inOrderStart, position-1, n, nodeToIndex);
        root->right = solve(in, pre, index, position+1, inOrderEnd, n, nodeToIndex);
        return root;
    }
    
    Node* buildTree(int in[],int pre[], int n)
    {
        int preOrderIndex = 0;
        map<int, int> nodeToIndex;
        
        //create nodes to index map
        createMapping(in, nodeToIndex, n);
        Node* ans = solve(in, pre, preOrderIndex, 0, n-1, n, nodeToIndex);
        return ans;
    }
};
