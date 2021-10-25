
https://practice.geeksforgeeks.org/problems/intersection-of-two-sorted-linked-lists/1

Node* findIntersection(Node* head1, Node* head2)
{
    // Your Code Here
    if(head1==NULL)
        return head2;
    if(head2==NULL)
        return head1;
    Node *ans=new Node(0),*point;
    while(head1 && head2){
        if(head1->data == head2->data){
            Node* temp=new Node(head1->data);
            if(ans->data == 0){
                ans=temp;point=temp;
            }
            else{
                point->next=temp;
                point=temp;
            }
            head1=head1->next;
            head2=head2->next;
        }
        else if(head1->data < head2->data)
            head1=head1->next;
        else
            head2=head2->next;
    }
    // while(head1){
    //     Node* temp=new Node(head1->data);
    //     if(ans==NULL){
    //             ans=temp;point=temp;
    //     }
    //     else{
    //         point->next=temp;
    //         point=temp;
    //     }
    //     head1=head1->next;
    // }
    // while(head2){
    //     Node* temp=new Node(head2->data);
    //     if(ans==NULL){
    //             ans=temp;point=temp;
    //     }
    //     else{
    //         point->next=temp;
    //         point=temp;
    //     }
    //     head2=head2->next;
    // }
    
    return ans;
}