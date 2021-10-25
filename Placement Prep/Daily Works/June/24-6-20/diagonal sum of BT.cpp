


https://practice.geeksforgeeks.org/problems/diagonal-sum-in-binary-tree/1


Iterative:

vector <int> diagonalSum(Node* root) {
    // Add your code here
    queue<pair<Node*,int>> q;
    map<int,int>mp;
 //   int h=height(root);
    vector<int>ans;
    q.push(make_pair(root,0));
    while(!q.empty()){
        auto it=q.front();
        q.pop();
        Node* temp=it.first;
       // int sum=0;
        while(temp){
            if(temp->left)
                q.push(make_pair(temp->left,it.second+1));
        mp[it.second]+=temp->data;
        temp=temp->right;
        }
    }
    for(auto a : mp){
        ans.push_back(a.second);
    }
    return ans;
}

Recursive:

void fill(Node* root,int dg,map<int,int> &mp){
	if(!root)
		return;
	mp[dp]+=root->data;
	fill(root->left,dg+1,mp);
	fill(root->right,dg,mp);
}

vector <int> diagonalSum(Node* root) {
	
	vector<int>ans;
	if(!root)
		return ans;
	map<int,int>mp;
	fill(root,0,mp);
	for(auto it:mp){
		ans.push_back(it.second);
	}
	return ans;
}