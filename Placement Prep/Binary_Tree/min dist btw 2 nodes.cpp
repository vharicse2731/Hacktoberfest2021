// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

int findDist(Node *, int, int);

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Node *root = buildTree(treeString);
        int n1, n2;
        scanf("%d %d ", &n1, &n2);
        cout << findDist(root, n1, n2) << "\n";
    }
    return 0;
}// } Driver Code Ends


/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

/* Should return minimum distance between a and b
   in a tree with given root*/
void findnode(Node* root,int a,int dist,int *d){
    if(root==NULL)
        return;
    if(root->data==a){
        *d=dist;
        
    }
    dist=dist+1;
    findnode(root->left,a,dist,d);
    findnode(root->right,a,dist,d);
}
void findmin(Node* root,int a,int b,int *min){
    if(root==NULL)
        return;
    int ad=INT_MAX,bd=INT_MAX;
    findnode(root,a,0,&ad);
//    cout<<"ad: "<<ad<<endl;
    findnode(root,b,0,&bd);
//    cout<<"bd: "<<bd<<endl;
    if((ad+bd)>=0 && (*min)>ad+bd){
//        cout<<"root: "<<root->data<<endl;

        *min=ad+bd;
//        cout<<"min: "<<*min<<endl;
    }
    findmin(root->left,a,b,min);
    findmin(root->right,a,b,min);
}
int findDist(Node* root, int a, int b) {
    // Your code here
    if(!root)
        return 0;
    int sum=INT_MAX;
    findmin(root,a,b,&sum);
    return sum;
}