

//  https://practice.geeksforgeeks.org/problems/ancestors-in-binary-tree/1/

STACK:

void maderes(Node* root,int t,int *a,stack<int> &temp){
    if(root==NULL || !(*a))
        return;
    if(root->data==t){
        while(!temp.empty()){
            cout<<temp.top()<<" ";
            temp.pop();
        }
        *a=0;
        return;
    }
       // fin=temp;
    temp.push(root->data);
    maderes(root->left,t,a,temp);
    maderes(root->right,t,a,temp);
    temp.pop();
}

bool printAncestors(struct Node *root, int target)
{
     // Code here
    stack<int>temp;int t=1;
    maderes(root,target,&t,temp);
    return true;
}

// RECURSION

bool printAncestors(struct Node *root, int key)
{
	if(!root) return false;
	if(root->data==key)
		return true;

	if(printAncestors(root->left,key) or printAncestors(root->right,key) )
	{
		cout<<root->data<<" ";
		return true;
	}
}