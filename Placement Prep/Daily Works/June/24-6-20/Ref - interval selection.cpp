
// https://www.hackerrank.com/contests/acm-placement-dp/challenges/interval-selection

// https://www.hackerrank.com/contests/acm-placement-dp/challenges/interval-selection/editorial

#include <bits/stdc++.h>

using namespace std;

pair <int, int> arr [1000 + 1];

bool compare(const pair <int, int> & p1, const pair <int, int> & p2){

    return (p1.second < p2.second);
}

int main ()
{
    ios::sync_with_stdio(false);cin.tie(0);

    int t, a, b, ans, n;
    int last, limit;

    cin >> t;

    for (int i = 0; i < t; i++) {

        ans = 1;
        last = limit = 0;
        cin >> n;

        for (int j = 0; j < n ; j++) {

            cin >> a >> b;
            arr[j] = make_pair(a, b);
        }

        sort(arr, arr + n, compare);

        for (int j = 1; j < n; j++) {

            if (arr[j].first > arr[last].second) {

                last = j;
                ans++;
            }

            else if (arr[j].first > limit) {

                limit = arr[last].second;
                last = j;
                ans++;
            }
        }

        cout << ans << "\n";
    }

    return 0;
}