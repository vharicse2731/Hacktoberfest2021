
// https://practice.geeksforgeeks.org/problems/check-for-bst/1

bool istree(Node* root,Node *&prev){
    if(root){
    if(!istree(root->left,prev))
        return 0;
    if(prev!=NULL && prev->data >=root->data)
        return 0;
    prev = root;
    if(!istree(root->right,prev))
        return 0;
    }
    return 1;
}

bool isBST(Node* root) {
   Node* prev=NULL;
   return istree(root,prev);
}