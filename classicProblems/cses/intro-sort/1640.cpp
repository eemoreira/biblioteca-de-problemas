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
    int n, x;
    cin >> n >> x;
    map<int,vector<int>> f;
    bool found = false;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (!found && !f[x - a].empty()) {
            cout << f[x - a][0] + 1 << ' ' << i + 1 << '\n';
            found = true;
        }
        f[a].emplace_back(i);
    }
    if (!found) cout << "IMPOSSIBLE\n";
}





