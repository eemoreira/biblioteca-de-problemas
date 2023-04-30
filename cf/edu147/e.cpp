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

/* stop freaking out pls */

string change(string s, int to, int from) {
    string ans = s.substr(0,to + 1) + s[from];
    for (int i = to + 1; i < from; i++) ans += s[i];
    for (int i = from + 1; i < (int)s.size(); i++) ans += s[i];
    return ans;
}

void calc(string &s) {
    int n = s.size();
    vector<int> stk, close(n);
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            stk.emplace_back(i);
        }
        else {
            assert(!stk.empty());
            close[stk.back()] = i;
            stk.pop_back();
        }
    }
    assert(stk.empty());
    int pos = 0;
    int mx = 0;
    for (int i = 0; i < n; i++) {
        if (close[i] - i > mx) {
            mx = close[i] - i;
            pos = i;
        }
    }
    s = change(s, pos, close[pos]);
}

void solve() {
    int k;
    string s;
    cin >> k >> s;
    for (int i = 0; i < k; i++) {
        calc(s);
    }
    dbg(s);
    int n = s.size();
    ll ans = 0;
    int cnt = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == ')') {
            cnt++;
        }
        else {
            if (cnt > 1) ans += cnt - 1;
            cnt--;
        }
    }
    cout << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
}





