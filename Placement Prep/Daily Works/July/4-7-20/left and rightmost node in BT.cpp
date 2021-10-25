

// https://practice.geeksforgeeks.org/problems/leftmost-and-rightmost-nodes-of-binary-tree/1

void printCorner(Node *root)
{
    queue<Node*>q;
    int n;
    Node* temp;
    q.push(root);
    while(!q.empty()){
        n=q.size();
        if(n==1)
            cout<<q.front()->data<<" ";
        else
            cout<<q.front()->data<<" "<<q.back()->data<<" ";
        while(n--){
            temp=q.front();
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
            q.pop();
        }
    }
}