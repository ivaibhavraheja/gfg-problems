class Solution
{
    public:
    void flatten(Node *root)
    {
        Node* curr = root;
        while(curr != NULL){
            if(curr->left){
                Node* pred = curr->left;
                //reach to the predecessor of curr
                while(pred->right){
                    pred = pred->right;
                }
                pred->right = curr->right;
                curr->right = curr->left;
                curr->left = NULL;        //because no usage of left of curr;
            }
            curr = curr -> right;
        }
    }
};
