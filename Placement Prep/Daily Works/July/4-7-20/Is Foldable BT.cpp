
//  https://practice.geeksforgeeks.org/problems/foldable-binary-tree/1/

bool fold(Node* rootl,Node* rootr){
    if(!rootl && !rootr)
        return 1;
    if(!rootl || !rootr)
        return 0;
    return fold(rootl->left,rootr->right)&&fold(rootl->right,rootr->left);
}
bool IsFoldable(Node* root)
{
    // Your code goes here
    if(!root)
        return 1;
    return fold(root->left,root->right);
}