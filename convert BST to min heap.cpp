void inorder(BinaryTreeNode* root, vector<int> &inTraversal){
    if(root == NULL)
        return ;
    inorder(root->left, inTraversal);
    inTraversal.push_back(root->data);
    inorder(root->right, inTraversal);
}

void fillPreOrder(BinaryTreeNode* root, vector<int> &inTraversal, int& index){
    if(root == NULL)
        return;
    //N < L < R -> preorder
    root->data = inTraversal[index++];
    fillPreOrder(root->left, inTraversal, index);
    fillPreOrder(root->right, inTraversal, index);
}

BinaryTreeNode* convertBST(BinaryTreeNode* root)
{
	vector<int> inTraversal;
    inorder(root, inTraversal);
    int index = 0;
    fillPreOrder(root, inTraversal, index);
    return root;
}
