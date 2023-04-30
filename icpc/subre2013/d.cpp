#include<bits/stdc++.h>
using namespace std;

vector<int> b;
map<vector<int>, int> dp;

bool go(vector<int> a) {
    int n = a.size();
    bool ok = false;
    if (dp.count(a)) return dp[a];

    if (a.size() < b.size()) return false;

    if (a == b) return true;
    vector<int> check = a;
    reverse(check.begin(), check.end());
    if (check == b) return true;

    for (int i = 0; i < n - 1; i++) {
        vector<int> now = a;
        int l = i, r = i + 1;
        while (l >= 0 && r < n) {
            now[l] = now[r] = now[l] + now[r];
            --l; ++r;
        }
        vector<int> next, next2, t;
        for (int j = 0; j <= l; j++) next.emplace_back(now[j]); 
        for (int j = i + 1; j < n; j++) next.emplace_back(now[j]);
        ok |= go(next);
        for (int j = 0; j <= l; j++) next2.emplace_back(now[j]);
        for (int j = i + 1; j < n; j++) t.emplace_back(now[j]);
        reverse(t.begin(), t.end());
        for (auto u : t) next2.emplace_back(u);
        ok |= go(next2);
    }
    return dp[a] = ok;
}

void solve() {
    int n, m;
    cin >> n;
    vector<int> a(n);
    for (auto &u : a) cin >> u;
    cin >> m;
    b = vector<int>(m);
    for (auto &u : b) cin >> u;
    cout << (go(a) ? "S\n" : "N\n");
}

int main() {
    cout.sync_with_stdio(0);
    cin.tie(0);
    solve();
}

