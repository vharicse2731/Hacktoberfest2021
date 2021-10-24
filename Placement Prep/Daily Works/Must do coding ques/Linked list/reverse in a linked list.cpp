
// https://practice.geeksforgeeks.org/problems/reverse-a-linked-list/1

USING ITERATIVE (3 POINTERS):

struct Node* reverseList(struct Node *head)
{
    Node* prev=NULL,*N=head->next;
    while(N){
        head->next=prev;
        prev=head;
        head=N;
        N=N->next;
    }
    head->next=prev;
    return head;
}

USING RECURSIVE:

Node* helper(Node* head,Node* prev){
    if(head==NULL)
        return prev;  // set the last element as root
    Node* curhead=helper(head->next,head); // call for recursive backwards
    head->next=prev; // assigning the connections  ie., 5 -> 6 to 5 <- 6
    return curhead;  // keep track of last element as head
}

struct Node* reverseList( Node *head){
    return helper(head,NULL);
}

}