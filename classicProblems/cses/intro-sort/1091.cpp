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
    int n, m;
    cin >> n >> m;
    multiset<int> a;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a.emplace(x);
    }
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        if (a.empty()) {
            cout << -1 << '\n';
            continue;
        }
        auto ans = a.upper_bound(x);
        if (ans == a.end()) --ans;
        if (*ans > x && ans == a.begin()) cout << -1 << '\n';
        else {
            if (*ans > x) --ans;
            cout << *ans << '\n';
            a.erase(ans);
        }
    }
}





