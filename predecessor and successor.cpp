void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{
    if(root == NULL){
        return ;
    }
    if(root->key == key){
        //checking if left subtree of given node exists
        if(root->left != NULL){
            Node* temp = root->left;
            while(temp->right){
                temp = temp->right;
            }
            pre = temp;
        }
        
        //checking if right subtree of given node exists
        if(root->right != NULL){
            Node* temp = root->right;
            while(temp->left){
                temp = temp->left;
            }
            suc = temp;
        }
        return ;
    }
    
    else if(root->key > key){
        suc = root;
        findPreSuc(root->left, pre, suc, key);
    }
    else{
        pre = root;
        findPreSuc(root->right, pre, suc, key);
    }
}
