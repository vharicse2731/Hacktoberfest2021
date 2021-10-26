#include<bits/stdc++.h>
using namespace std;
bool notFound(vector<int>& match, vector<int>& prev) {
    if(prev.size() == 0) {
        return true;
    }
    if(match[0] == prev[0] || match[1] == prev[0] || match[0] == prev[1] || match[1] == prev[1]) {
        return false;
    }
    return true;
}
int main() {
    int n = 10;
    vector<int>teams;
    for(int i = 1; i <= n; i++) {
        teams.push_back(i);
    }
    int s = 0;
    vector<vector<int > >matches;
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            if(teams[i] != teams[j]) {
                matches.push_back({teams[i], teams[j]});
                //cout << teams[i] << " " << teams[j] << endl;
            }
        }
    }
    //cout << matches.size();
    bool completed[matches.size()];
    memset(completed, false, sizeof(completed));
    vector<int>prev;
    int m = 0;
    for(int i = 0; i < matches.size(); i++) {
        /*if(false) {
            vector<int>first, second;
            for(int i = 0; i < matches.size(); i++) {
                if(notFound(matches[i], prev)) {
                    first = matches[i];
                    break;
                }
            }
            for(int i = 0; i < matches.size(); i++) {
                if(notFound(matches[i], prev) && notFirstMatch(matches[i], first)) {
                    second = matches[i];
                    break;
                }
            }
            prev.clear();
            prev.push_back(first[0]);
            prev.push_back(first[1]);
            prev.push_back(second[0]);
            prev.push_back(second[1]);
        }*/
        //else {
            for(int i = 0; i < matches.size(); i++) {
                if(!completed[i] && notFound(matches[i], prev)) {
                    cout << s << " " << matches[i][0] << " " << matches[i][1] << endl;
                    completed[i] = true;
                    prev.clear();
                    prev.push_back(matches[i][0]);
                    prev.push_back(matches[i][1]);
                    m++;
                    break;
                }
            }
        //}
        s = (s + 1) % 7;
    }
    cout << m;
    return 0;
}
/*
Cricket tournament
10 teams
Maximum three double headers allowed in a week(Sat,Sun mandatory)
Each team will play two phases
In first phase, a team will play once with every other team
In second phase, a team will play 5 out of remaining 9 teams(5 teams which are closer to the particular team in the points table during phase I)
A team shoudn't play consecutive days or matches
Two quailifiers,One final
Minimum days required to conduct the tournament
*/
