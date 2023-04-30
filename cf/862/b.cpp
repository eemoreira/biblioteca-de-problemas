#include <bits/stdc++.h>

using namespace std;
typedef tuple<int,int,int> i3;
typedef long long ll;

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

/* stop freaking out pls */
void solve() {
    int n;
    string s;
    cin >> n >> s;
    set<char> t;
    for (auto u : s) t.emplace(u);
    char c = *t.begin();
    int ptr = 0;
    while (ptr < n && s[ptr] == c) ptr++;
    for (int i = n - 1; i >= ptr; i--) {
        if (c == s[i]) {
            cout << c;
            for (int j = 0; j < i; j++) cout << s[j];
            for (int j = i + 1; j < n; j++) cout << s[j];
            cout << '\n';
            return;
        }
    }
    cout << s << '\n';
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





