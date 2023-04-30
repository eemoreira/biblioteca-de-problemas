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
    int n, q;
    cin >> n >> q;
    vector<vector<ll>> a(n + 1, vector<ll>(n + 1)), p(n + 1, vector<ll>(n + 1));
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        for (int j = 1; j <= n; j++) {
            a[i][j] = s[j-1] == '*';
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            p[i][j] = p[i][j-1] + p[i-1][j] - p[i-1][j-1] + a[i][j];
        }
    }
    while (q--) {
        int x0, y0, x1, y1;
        cin >> x0 >> y0 >> x1 >> y1;
        cout << p[x1][y1] - p[x1][y0-1] - p[x0-1][y1] + p[x0-1][y0-1] << '\n';
    }
}





