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

const int MAX = 1e6 + 5;
int lp[MAX+1], factor[MAX+1];
vector<int> pr;

namespace sieve {
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
    int n, m;
    cin >> n >> m;
    vector<int> f = sieve::factorize(n);
    if (!f.empty() && f[0] <= m) {
        cout << "NO\n";
    }
    else {
        cout << "YES\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    sieve::build();
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
}





