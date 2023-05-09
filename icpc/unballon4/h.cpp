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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, k;
    cin >> n >> m >> k;
    string s, t;
    cin >> s >> t;
    if (k > m) {
        cout << "S\n";
        return 0;
    }
    vector<vector<int>> dp(n + 1, vector<int>(26, 1e9));
    for (int i = n - 1; i >= 0; i--) {
        dp[i][s[i] - 'a'] = i;
        for (int j = 0; j < 26; j++) {
            dp[i][j] = min(dp[i + 1][j], dp[i][j]);
        }
    }
    int x = 0;
    for (int i = 0; i < m; i++) {
        int now = dp[0][t[i] - 'a'];
        dbg(t[i], now);
        if (now == 1e9) {
            cout << "S\n"; 
            return 0;
        }
        while (i < m - 1 && dp[now][t[i + 1] - 'a'] != 1e9) {
            i++;
            now = dp[now][t[i] - 'a'];
        }
        x++;
    }
    cout << (x <= k ? "N\n" : "S\n");
}





