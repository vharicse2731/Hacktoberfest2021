
// https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1

USING RECURSION:

int lvl(Node* root,int l){
    if(root==NULL)
        return -1;
    if(l==1)
        return root->data;
        
    int x=lvl(root->left,l-1);
    if(x!=-1)
        return x;
    return lvl(root->right,l-1);
}

int height(Node* root){
    if(!root)
        return 0;
    return max(height(root->left),height(root->right))+1;
}

void leftView(Node *root)
{
    int h=height(root);
    for(int i=1;i<=h;i++)
        cout<<lvl(root,i)<<" ";
}


USING ITERATIVE:

void leftView(Node *root)
{
    if(!root)
        return;
    queue<Node*>q;
    q.push(root);
    int n;
    while(!q.empty()){
        n=q.size();
        cout<<q.front()->data<<" ";
        while(n!=0){
            Node* temp = q.front();
            q.pop();
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
            n--;
        }
    }
}