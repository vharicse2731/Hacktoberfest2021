

// https://practice.geeksforgeeks.org/problems/remove-loop-in-linked-list/1

void removeLoop(Node* head)
{
    Node *slow=head,*fast=head;
    Node* prev;
    while(fast && fast->next){
        prev=slow;
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)
            break;			// identifies cycle
    }
    if(slow!=fast)
        return;
    if(slow==head){
        prev->next=NULL;
        return;
    }
    
    slow=head;
    while(slow->next!=fast->next){
        slow=slow->next;
        fast=fast->next;
    }
    fast->next=NULL;
}