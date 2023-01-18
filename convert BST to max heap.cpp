class Solution{
  private:
    void getInorder(Node* root, vector<int> &inorder){
        if(root == NULL){
            return;
        }
        getInorder(root->left, inorder);
        inorder.push_back(root->data);
        getInorder(root->right, inorder);
    }
    void convertToPostorder(Node* root, vector<int> &inorder, int &index){
        //L < R < N --> postorder
        if(root == NULL){
            return;
        }
        convertToPostorder(root->left, inorder, index);
        convertToPostorder(root->right, inorder, index);
        root->data = inorder[index++];
    }
  public:
    void convertToMaxHeapUtil(Node* root)
    {
        vector<int> inorder;
        int index = 0;
        getInorder(root, inorder);
        convertToPostorder(root, inorder, index);
    }    
};
