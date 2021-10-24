
// https://practice.geeksforgeeks.org/problems/nth-node-from-end-of-linked-list/1


With LENGTH:

int getNthFromLast(Node *head, int n)
{
    Node *slow=head,*fast=head;
    int no=1;
    while(fast && fast->next){
        no+=2;
        fast=fast->next->next;
    }
    if(!fast)
        no--;
    int cou=no-n;
    if(cou<0)
        return -1;
    if(cou==0)
        return head->data;
    while(slow && cou--)
        slow=slow->next;
    return slow->data;
}

without finding length:

class GfG{
    public int getNthFromLast(Node head, int n){
        Node p = head, f = head;
        for(int i=1; i<=n-1; i++){
            f = f.next;
            if(f == null) return -1;
        }
        while(f.next != null){
            p = p.next;
            f = f.next;
        }
        return p.data;
    }
}