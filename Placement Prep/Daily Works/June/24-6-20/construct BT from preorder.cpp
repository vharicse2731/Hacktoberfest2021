
// https://practice.geeksforgeeks.org/problems/construct-tree-from-preorder-traversal/1

Node* filltree(int pre[],char preln[],int *i,int n){
    if(*i>=n)
        return NULL;
    
    Node* root=new Node(pre[*i]);
    
    if(preln[*i]=='N'){
      //  root=temp;
        (*i)++;
        root->left=filltree(pre,preln,i,n);
        (*i)++;
        root->right=filltree(pre,preln,i,n);
    }

        
    return root;
}
struct Node *constructTree(int n, int pre[], char preLN[])
{
    // Code here
    if(n==0)
        return NULL;
    int i=0;
    Node* root=filltree(pre,preLN,&i,n);
    return root;
}