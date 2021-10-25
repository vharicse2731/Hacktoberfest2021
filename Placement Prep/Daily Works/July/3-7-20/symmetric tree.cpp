

//  https://practice.geeksforgeeks.org/problems/symmetric-tree/1

bool issym(Node* rootl,Node* rootr){
    if(!rootl && !rootr)
        return 1;
    if(!rootl || !rootr)
        return 0;
    return rootl->data==rootr->data && issym(rootl->left,rootr->right) && issym(rootl->right,rootr->left);
}
bool isSymmetric(struct Node* root)
{
	// Code here
	if(!root)
	    return 1;
	return issym(root->left,root->right);
}