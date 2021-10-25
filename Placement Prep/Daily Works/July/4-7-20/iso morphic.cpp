
//  https://practice.geeksforgeeks.org/problems/check-if-tree-is-isomorphic/1


bool iso(Node* r1,Node* r2){
    if(!r1 && !r2)
        return true;
    if(!r1 || !r2)
        return false;
    if(r1->data != r2->data)
        return false;
    return (iso(r1->left,r2->left)&&iso(r1->right,r2->right)) || (iso(r1->left,r2->right)&&iso(r1->right,r2->left));
}
bool isIsomorphic(Node *root1,Node *root2)
{
    return iso(root1,root2);
}