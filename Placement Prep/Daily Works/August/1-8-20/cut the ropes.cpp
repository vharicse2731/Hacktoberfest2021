

/*

I/P:
N K

n --> ropes 
k --> max cut 
..
N integers as i/p:
contains numbers from 1 to N in diff order.

cut the ropes of max K segment size.. 
in which all ropes turn into the min length ropes in that segment.

O/P:
min operations to cut all ropes;

I/P:
5 4
2 1 3 4 5

O/P:
2

Expl:
1 1 1 1 5  --> 1
1 1 1 1 1  --> 2

*/

//https://www.hackerrank.com/contests/all-india-contest-by-mission-helix-01-august/challenges/cut-the-ropes/problem

using namespace std;

int main() {
    int n,k;
    cin>>n>>k;
    int i=k,count=1;
    while(i<n){
        count++;
        i+=(k-1);
    }
    cout<<count;
    return 0;
}