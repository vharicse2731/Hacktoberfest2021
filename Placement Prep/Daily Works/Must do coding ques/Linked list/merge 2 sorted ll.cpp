
// https://practice.geeksforgeeks.org/problems/merge-two-sorted-linked-lists/1

ITERATIVE :

Node* sortedMerge(Node* h1, Node* h2)  
{   if(!h1)
        return h2;
    if(!h2)
        return h1;
    Node *prev,*temp;
    if(h2->data < h1->data){
        prev=h1;
        h1=h2;
        h2=prev;
    }
    Node *cur=h1;
    while(cur && h2){
        if(cur->data <= h2->data){
            prev=cur;
            cur=cur->next;
        }
        else{
            temp=h2;
            h2=h2->next;
            prev->next=temp;
            temp->next=cur;
            prev=temp;
        }
    }
 //   cout<<cur->data<<endl;
    while(h2){
        prev->next=h2;
        h2=h2->next;
        prev=prev->next;
    }
    return h1;
}


RECURSIVE :

Node* SortedMerge(Node* head1, Node* head2)
{
	if(head1 == NULL)
		return head2;
	if(head2 == NULL)
		return head1;

	if(head1->data < head2->data) {
		head1->next = SortedMerge(head1->next,head2);
		return head1;
	} 
	else {
		head2->next = SortedMerge(head1,head2->next);
		return head2;
	}
}