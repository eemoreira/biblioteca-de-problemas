#include <bits/stdc++.h>

using namespace std;
typedef tuple<int,int,int> i3;
typedef long long ll;
typedef pair<int,int> ii;

#ifdef DEBUG
#include "debug.h"
#else
#define dbg(x...)
#endif

/* stop freaking out pls */
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (auto& u : a) cin >> u;
    set<ll> s;
    s.emplace(0);
    vector<ll> ans(k + 1);
    dbg(a);
    for (int i = 0; i <= k; i++) {
        ans[i] = *s.begin();
        s.erase(s.begin());
        while (i && ans[i] == ans[i - 1]) {
            assert(!s.empty());
            ans[i] = *s.begin();
            s.erase(s.begin());
        }
        for (int j = 0; j < n; j++) {
            s.emplace(ans[i] + a[j]);
        }
    }
    cout << ans[k] << '\n';
}





