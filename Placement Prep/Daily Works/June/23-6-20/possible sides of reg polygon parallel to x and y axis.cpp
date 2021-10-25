#include<iostream>
using namespace std;
int main(){
    int t;
    int num;
    cin>>t;
    while(t--){
        cin>>num;
        if(num==0)						//cin>>num;
            cout<<"NO"<<endl;			//cout<<(num%4==0)?"YES":"NO"<<endl;
        else{
            if(num%4==0)
                cout<<"YES"<<endl;
            else
                cout<<"NO"<<endl;
        }
    }
    return 0;
}