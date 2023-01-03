Node* merge(Node* down, Node* right){
    if(down == NULL)
        return right;
    if(right == NULL)
        return down;
    Node* ans = new Node(-1);
    Node* temp = ans;
    while(down != NULL && right != NULL){
        if(down->data < right->data){
            temp->bottom = down;
            temp = down;
            down = down->bottom;
        }
        else{
            temp->bottom = right;
            temp = right;
            right= right->bottom;
        }
    }
    while(down != NULL){
        temp->bottom = down;
        temp = down;
        down = down->bottom;
    }
    while(right != NULL){
        temp->bottom = right;
        temp = right;
        right= right->bottom;
    }
    ans = ans->bottom;
    return ans;
}
Node *flatten(Node *head)
{
   //base case
   if(head == NULL || head->next == NULL){
       return head;
   }
   
   //divide into two linked list
   Node* down = head;
   Node* right = head->next;
   down->next = NULL;
   
   //recursive call for right linked list
   right = flatten(right);
   
   //merge both sorted linked list
   Node* ans = merge(down, right);
   return ans;
}
