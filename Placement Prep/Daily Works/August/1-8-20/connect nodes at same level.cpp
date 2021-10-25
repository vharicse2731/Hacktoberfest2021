


// connect nodes at same level

// https://practice.geeksforgeeks.org/problems/connect-nodes-at-same-level/1



void connect(Node *p)
{
   queue<Node*>q;
   Node* temp;
   int n;
   q.push(p);
   while(!q.empty()){
       n=q.size();
       while(n--){
            temp=q.front();
            q.pop();
            if(n!=0){
                temp->nextRight=q.front();
            }
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
       }
   }
}