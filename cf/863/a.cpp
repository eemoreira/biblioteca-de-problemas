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
    char d;
    cin >> n >> d;
    string s;
    cin >> s;

    for (int i = 0; i < n; i++) {
        if (d > s[i]) {
            for (int j = 0; j < i; j++) cout << s[j];
            cout << d;
            for (int j = i; j < n; j++) cout << s[j];
            cout << '\n';
            return;
        }
    }
    s += d;
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





