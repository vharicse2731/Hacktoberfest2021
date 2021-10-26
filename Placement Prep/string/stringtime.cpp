#include<iostream>
using namespace std;
int main() {
    string ans;
    for(int i = 0; i < 10000; i++) {
        ans = ans + to_string(i);
    }
    cout << "finished";
    return 0;
}
