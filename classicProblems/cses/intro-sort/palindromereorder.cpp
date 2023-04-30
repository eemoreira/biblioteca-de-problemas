#include <bits/stdc++.h>

using namespace std;
typedef tuple<int,int,int> i3;
typedef long long ll;
typedef pair<int,int> ii;

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    vector<int> f(26);
    for (auto u : s) f[u - 'A']++;
    deque<char> ans;
    int found = -1;
    for (int i = 0; i < 26; i++) {
        if (f[i] & 1) {
            if (found != -1) {
                cout << "NO SOLUTION\n";
                return 0;
            }
            found = i;
            continue;
        }
        while (f[i]) {
            f[i] -= 2;
            ans.emplace_front(i + 'A');
            ans.emplace_back(i + 'A');
        }
    }
    if (found != -1) {
        while (f[found] > 1) {
            f[found] -= 2;
            ans.emplace_front(found + 'A');
            ans.emplace_back(found + 'A');
        }
        int n = ans.size();
        for (int i = 0; i < n/2; i++) cout << ans[i];
        cout << char(found + 'A');
        for (int i = n/2; i < n; i++) cout << ans[i];
        cout << '\n';
    }
    else {
        for (auto u : ans) cout << u;
        cout << '\n';
    }
}





