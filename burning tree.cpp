class Solution {
  public:
    //creates mapping
    //return target node
    Node* createParentMapping(Node* root, int target, map<Node*, Node*> &nodeToParent){
        Node* res;
        queue<Node*> q;
        q.push(root);
        //root ka parent NULL daldo
        nodeToParent[root] = NULL;
        while(!q.empty()){
            Node* front = q.front();
            q.pop();
            
            if(front->data == target){
                res = front;
            }
            if(front->left){
                nodeToParent[front->left] = front;
                q.push(front->left);
            }
            if(front->right){
                nodeToParent[front->right] = front;
                q.push(front->right);
            }
        }
        return res;
    }
    
    
    int burnTree(Node* root, map<Node*,Node*> &nodeToParent){
        map<Node*, bool> visited;
        visited[root] = 1;
        
        queue<Node*> q;
        q.push(root);
        int ans = 0;
        while(!q.empty()){
            bool flag = 0;          //for checking if any element is pushed in queue or not
            int size = q.size();
            for(int i=0; i<size; i++){
                //process neighbouring nodes
                Node* front = q.front();
                q.pop();
                
                if(front->left && !visited[front->left]){
                    visited[front->left] = 1;
                    q.push(front->left);
                    flag = 1;
                }
                if(front->right && !visited[front->right]){
                    visited[front->right] = 1;
                    q.push(front->right);
                    flag = 1;
                }
                if(nodeToParent[front] && !visited[nodeToParent[front]]){
                    visited[nodeToParent[front]] = 1;
                    q.push(nodeToParent[front]);
                    flag = 1;
                }
            }
            if(flag == 1){
                ans++;
            }
        }
        return ans;
    }
    
    int minTime(Node* root, int target) 
    {
        // algo:
        //step1: create node to parent target mapping
        //step2: find target node
        //step3: burn tree in minimum time
        
        map<Node*, Node*> nodeToParent;
        Node* targetNode = createParentMapping(root, target, nodeToParent);
        
        int ans = burnTree(targetNode, nodeToParent);
        return ans;
    }
};
