
// https://practice.geeksforgeeks.org/problems/permutations-of-a-given-string/0


USING INBUILT FUNCTION:

void solve(){
    string s;
    cin>>s;
    sort(s.begin(),s.end());
    do{
        cout<<s<<" ";
    }while(next_permutation(s.begin(),s.end()));
}


USING RECURSION (Without Maintaining Order):

void print(string s,int l,int r){
    if(l==r){
        cout<<s<<" ";
		return;
	}
    for(int i=l;i<=r;i++){
        swap(s[i],s[l]);
        print(s,l+1,r);
        swap(s[i],s[l]);
    }
}

void solve(){
    string s;
    cin>>s;
    sort(s.begin(),s.end());
    print(s,0,s.size()-1);
}

MAINTAING ORDER:

vector<string> ans;
void print(string s,int l,int r){
    if(l==r){
        ans.push_back(s);
		return;
	}
    for(int i=l;i<=r;i++){
        swap(s[i],s[l]);
        print(s,l+1,r);
        swap(s[i],s[l]);
    }
}

void solve(){
    string s;
    cin>>s;
 //   sort(s.begin(),s.end());
    ans.clear();
    print(s,0,s.size()-1);
    sort(ans.begin(),ans.end());
    for(auto a:ans)
        cout<<a<<" ";
}

USING ROTATE :

vector<string> ans;
void print(string s,string t){
    if(s.size()==0){
        ans.push_back(t);
		return;
	}
	for(int i=0;i<s.size();i++){
        print(s.substr(1),t+s[0]);
        rotate(s.begin(),s.begin()+1,s.end());
	}
}

void solve(){
    string s;
    cin>>s;
 //   sort(s.begin(),s.end());
    ans.clear();
    print(s,"");
    sort(ans.begin(),ans.end());
    for(auto a:ans)
        cout<<a<<" ";
}


