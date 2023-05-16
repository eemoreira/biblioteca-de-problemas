#include <bits/stdc++.h>

using namespace std;
typedef tuple<int,int,int> i3;
typedef long long ll;
typedef pair<int,int> ii;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define dbg(x...)
#endif

/* stop freaking out pls */
void solve() {
    string s;
    cin >> s;
    int n = s.size();
    for (int i = 1; i < n; i++) {
        if (s[i] != s[i - 1] && (n % 2 == 0 || (i != n / 2 && (i - 1) != n / 2))) {
            cout << "yes\n";
            return;
        }
    }
    cout << "no\n";
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





