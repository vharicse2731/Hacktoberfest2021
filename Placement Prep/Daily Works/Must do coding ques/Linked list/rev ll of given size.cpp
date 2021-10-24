

// https://practice.geeksforgeeks.org/problems/reverse-a-linked-list-in-groups-of-given-size/1

/*
Input:
2
8
1 2 2 4 5 6 7 8
4
5
1 2 3 4 5
3

Output:
4 2 2 1 8 7 6 5
3 2 1 5 4
*/

struct node *reverse (struct node *head, int k)
{ 
    struct node* prev=NULL,*N,*cur=head;
    int c=k;
    while(c-- && cur){
        N=cur->next;
        cur->next=prev;
        prev=cur;
        cur=N;
    }
    if(head!=NULL){
        head->next=reverse(cur,k);
    }
    return prev;
}