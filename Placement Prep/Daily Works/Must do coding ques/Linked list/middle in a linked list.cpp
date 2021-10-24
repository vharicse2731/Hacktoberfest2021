


int getMiddle(Node *head)
{
    Node* slow=head,*fast=head;
    while(fast->next && fast->next->next){
       slow=slow->next;
       fast=fast->next->next;
    }
    if(fast->next)
        slow=slow->next;
    return slow->data;
}