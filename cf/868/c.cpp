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


const int MAX = 1e7 + 1;
int lp[MAX+1], factor[MAX+1];
namespace sieve {
    vector<int> pr;
    void build() {
        for (int i = 2; i <= MAX; ++i) {
            if (lp[i] == 0) {
                lp[i] = i;
                pr.push_back(i);
            }
            for (int j = 0; i * pr[j] <= MAX; ++j) {
                lp[i * pr[j]] = pr[j];
                factor[i * pr[j]] = i;
                if (pr[j] == lp[i]) break;
            }
        }
    }
    vector<int> factorize(int x) {
        if (x < 2) return {};
        vector <int> v;
        for (int lpx = lp[x]; x >= lpx; x = factor[x]) v.emplace_back(lp[x]);
        return v;
    }
}

void solve() {
    int n;
    cin >> n;
    vector<int> r(n);
    for (auto &u : r) cin >> u;
    vector<int> a;
    for (int i = 0; i < n; i++) {
        vector<int> f = sieve::factorize(r[i]);
        for (auto u : f) a.emplace_back(u);
    }
    sort(a.begin(), a.end());
    dbg(a);
    map<int,int> f;
    for (auto u : a) f[u]++;
    int ans = 0;
    int cnt = 0;
    for (auto u : f) {
        cnt += u.second & 1;
        ans += u.second >> 1;
    }
    n = a.size();
    ans += cnt / 3;
    cout << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    sieve::build();
    cin >> tt;
    while (tt--) {
        solve();
    }
}





