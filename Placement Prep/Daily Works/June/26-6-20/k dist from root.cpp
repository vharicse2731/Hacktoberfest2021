
// https://practice.geeksforgeeks.org/problems/k-distance-from-root/1/


void lvl(Node* root,int l){
    if(root==NULL)
        return;
    if(l==0)
        cout<<root->data<<" ";
    else{
        lvl(root->left,l-1);
        lvl(root->right,l-1);
    }
    
}

void printKdistance(struct Node *root, int k)
{
  // Your code here
  lvl(root,k);
  
}