
// https://practice.geeksforgeeks.org/problems/height-of-spiral-tree/1/

int findTreeHeight(Node* root)
{
	// Code here
	if(!root)
	    return 0;
	if(root->right && root->right->left == root)
	    return 1;
	return max(findTreeHeight(root->left),findTreeHeight(root->right))+1;
	
}