

// https://practice.geeksforgeeks.org/problems/maximum-node-level/1/

RECURSIVE:

int height(Node* root){
    if(!root)
        return 0;
    return max(height(root->left),height(root->right))+1;
}
void lvl(Node* root,int l,int *count){
    if(!root )
        return;
    if(l==0)														//if(l==1)
        (*count)++;
    else{
        lvl(root->left,l-1,count);
        lvl(root->right,l-1,count);
    }
        
}
int maxNodeLevel(Node *root)
{
 // Add your code here
    int h=height(root);
    int maxi=0,temp,level=-1;
    for(int i=0;i<h;i++){  											//  for(int i=1;i<=h;i++){
        temp=0;
        lvl(root,i,&temp);
        if(maxi<temp){
            maxi=temp;
            level=i;
        }
    }
    return level;
}

ITERATIVE:

int maxNodeLevel(Node *root)
{
    
    if (root == NULL)
        return -1;
 
    queue<Node *> q;
    q.push(root);
 
    // Current level
    int level = 0;
 
    // Maximum Nodes at same level
    int max = INT_MIN;
 
    // Level having maximum Nodes
    int level_no = 0;
 
    while (1)
    {
        // Count Nodes in a level
        int NodeCount = q.size();
 
        if (NodeCount == 0)
            break;
 
        // If it is maximum till now
        // Update level_no to current level
        if (NodeCount > max)
        {
            max = NodeCount;
            level_no = level;
        }
 
        // Pop complete current level
        while (NodeCount > 0)
        {
            Node *Node = q.front();
            q.pop();
            if (Node->left != NULL)
                q.push(Node->left);
            if (Node->right != NULL)
                q.push(Node->right);
            NodeCount--;
        }
 
        // Increment for next level
        level++;
    }
 
    return level_no;

}
