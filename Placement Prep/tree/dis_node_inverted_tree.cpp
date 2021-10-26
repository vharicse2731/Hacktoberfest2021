#include<bits/stdc++.h>
using namespace std;
struct Node {
    int val;
    Node* next;
    public:
    Node(int val) {
        this->val = val;
        this->next = NULL;
    }
};
int findDistance(Node* node1, Node* node2) {
    vector<int> path1, path2;
    Node* ptr1 = node1;
    while(ptr1 != NULL) {
        path1.push_back(ptr1->val);
        ptr1 = ptr1->next;
    }
    Node* ptr2 = node2;
    while(ptr2 != NULL) {
        path2.push_back(ptr2->val);
        ptr2 = ptr2->next;
    }
    int i = path1.size() - 1, j = path2.size() - 1;
    while(i >= 0 && j >= 0) {
        if(path1[i] == path2[j]) {
            i--;
            j--;
        }
        else {
            break;
        }
    }
    return i + j + 2;
}
int main() {
    int n;
    cin >> n;
    vector<Node*> tree;
    tree.push_back(NULL);
    for(int i = 1; i <= n; i++) {
        Node* temp = new Node(i);
        tree.push_back(temp);
    }
    for(int i = 2; i <= n; i++) {
        tree[i]->next = tree[i / 2];
    }
    cout << "Tree" << endl;
    for(int i = 1; i <= n; i++) {
        if(i != 1)
            cout << tree[i]->val << " " << tree[i]->next->val << endl;
        else {
            cout << tree[i]->val << " " << " No Child" << endl;
        }
    }
    int node1, node2;
    cin >> node1 >> node2;
    int distance = findDistance(tree[node1], tree[node2]);
    cout << distance << endl;
    return 0;
}
