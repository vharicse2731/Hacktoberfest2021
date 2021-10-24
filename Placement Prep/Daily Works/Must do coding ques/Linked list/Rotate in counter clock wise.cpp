
//https://practice.geeksforgeeks.org/problems/rotate-a-linked-list/1

MINE : USING MOD

Node* rotate(Node* head, int k)
{
    if(!head || !head->next)
        return head;
    Node* cur=head,*temp;int cnt=1,t=k;
    
    while(k && cur->next){
        cur=cur->next;
        k--;cnt++;
    }
    if(k){
        t=t%cnt;
        cur=head;
        while(t){
            cur=cur->next;
            t--;
        }
    }
    temp=cur;
    while(temp->next)
        temp=temp->next;
    while(head!=cur){
        temp->next=head;
        head=head->next;
        temp=temp->next;
    }
    temp->next=NULL;
    return cur;
}


USING CIRCULAR LINKED LIST:

Node* rotate(Node* head, int k){
	Node* temp = head;
	while(temp->next){
		temp = temp->next;
	}
	temp->next = head; // linking last node with first node
	Node *end;
	while(k--){
		end = head;
		head = head->next;
	}
	end->next = NULL; // end is previous of updated head, so make end of next as null as it is the last node of updated linked list

	return head;
}


ALTER THE LINKED LIST EVERY TIME :
/*
4 5 6 6 7 --> k=3
5 6 6 7 4 - 1
6 6 7 4 5 - 2
6 7 4 5 6 - 3
*/
Node* rotate(Node* head, int k) {
    // Your code here
    Node* end=head,*ptr;
    while(end->next)
    end=end->next;
    while(k--)
    {
        ptr=head;
        head=head->next;
        ptr->next=NULL;
        end->next=ptr;
        end=ptr;
    }
    return head;
}