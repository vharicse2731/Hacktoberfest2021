// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


int maxDiff(Node *root);

// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if(currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if(currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


int main() {
    int t;
    string tc;
    getline(cin, tc);
    t=stoi(tc);
    while(t--)
    {
        string s ;
        getline(cin, s);
        Node* root = buildTree(s);
        
        cout<<maxDiff(root)<<endl;
    }
    return 0;
}

// } Driver Code Ends


/* A binary tree node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

/* Your are required to 
complete this method*/
/*int finddiff(Node *root){
    if(root==NULL)
        return 0;
    if(!root->left && !root->right)
        return 0;
    if(root->left && root->right)
        return max((root->data-root->left->data),(root->data-root->right->data));
    else if(root->left)
        return root->data-root->left->data;
    else
        return root->data-root->right->data;
}*/
/*void finddiff(Node* root,int *maxi){
    if(root==NULL)
        return;
    if(!root->left && !root->right)
        return;
    if(root->left && root->right)
        *maxi=max(*maxi,max((root->data-root->left->data),(root->data-root->right->data)));
    else if(root->left)
        *maxi=max(*maxi,root->data-root->left->data);
    else
        *maxi=max(*maxi,root->data-root->right->data);
    finddiff(root->left,maxi);
    finddiff(root->right,maxi);
}
int maxDiff(Node* root)
{
    // Your code here
    if(root==NULL)
        return 0;
    int maxi=INT_MIN;
    finddiff(root,&maxi);
    return maxi;
}*/
int minfind(Node* root,int *sum){
    if(root==NULL)
        return INT_MAX;
    if(!root->left && !root->right)
        return root->data;
//    int a=minnode(root->left);
//    int b=minnode(root->right);
    int c = min(minfind(root->left,sum),minfind(root->right,sum));
//    (*sum)<root->data-c ? (*sum)=root->data-c : (*sum);
    *sum=max((*sum),root->data-c);
    return min(c,root->data);
}
int maxDiff(Node* root)
{
    if(root==NULL)
        return 0;
    int sum=INT_MIN;
    minfind(root,&sum);
    return sum;
}
