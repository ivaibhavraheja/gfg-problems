//Function to insert string into TRIE.
void insert(struct TrieNode *root, string key)
{
    for(int i=0; i<key.size(); i++){
        int index = key[i]-'a';
        //letter absent
        if(root->children[index] == NULL){
            root->children[index] = new TrieNode();
        }
        //letter present
        root = root->children[index];
    }
    root->isLeaf = true;
}

//Function to use TRIE data structure and search the given string.

bool search(struct TrieNode *root, string key) 
{
    for(int i=0; i<key.size(); i++){
        int index = key[i]-'a';
        if(root->children[index] == NULL){
            return false;
        }
        root = root->children[index];
    }
    return root->isLeaf;
}
