
// https://practice.geeksforgeeks.org/problems/flattening-a-linked-list/1

/*
(i) a next pointer to the next node,
(ii) a bottom pointer to a linked list where this node is head.

	   5 -> 10 -> 19 -> 28
       |    |     |     |
       V    V     V     V
       7    20    22    35
       |          |     |
       V          V     V
       8          50    40
       |                |
       V                V
       30               45

*/

Node* merge(Node* a,Node* b){
    if(!a)
        return b;
    if(!b)
        return a;
    Node* r;
    if(a->data <= b->data){
        r=a;r->bottom=merge(a->bottom,b);
    }
    else{
        r=b;r->bottom=merge(a,b->bottom);
    }
    r->next=NULL;
    return r;
}

Node *flatten(Node *root)
{
    if(!root || !root->next)
        return root;
    return merge(root,flatten(root->next));
}