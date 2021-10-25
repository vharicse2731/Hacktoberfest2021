
/*

Simba considers a sequence of numbers nice only if there are no such pair of adjacent
 numbers in the sequence such that the pair consists of 
 both odd or both even number.

Simba received a sequence of numbers A from his friend as a birthday present. 
Can you tell if the sequence is nice to him or not?

I/p:
4
1 2 3 4

o/p:
YES

*/

// https://www.hackerrank.com/contests/all-india-contest-by-mission-helix-01-august/challenges/nice-array/submissions/code/1325387125


using namespace std;

bool solve(){
    int n;
    cin>>n;
    int now=0,prev;
    cin>>prev;
    
    bool ok=true;
    for(int i=1;i<n;i++){
        cin>>now;
        if(prev&1 && now&1)
            ok=false;
        else if(prev%2==0 && now%2==0)
            ok=false;
        prev=now;
    }
    return ok;
}
int main() {
    if(solve())
        cout<<"YES";
    else
        cout<<"NO";
    cout<<endl;
    return 0;
}