#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

/* stop freaking out pls */
struct SparseTable {
    int n, e;
    vector<vector<long long>> st;
    SparseTable(vector<long long> &v) : n(v.size()), e(floor(log2(n))) {
        st.assign(e+1, vector<long long>(n));
        for (int i = 0; i < n; i++) st[0][i] = v[i];
        for (int i = 1; i <= e; i++) {
            for (int j = 0; j + (1 << i) <= n; j++) {
                st[i][j] = max(st[i-1][j], st[i-1][j+(1 << (i-1))]);
            }
        }
    }
    int query(int l, int r) {
        if (r < l || l < 0 || r < 0) return 0;
        int i = ilogb(r-l+1);
        return max(st[i][l], st[i][r - (1 << i) + 1]);
    }
};

int n;
vector<long long> a;
vector<int> nxt_big, last_big;
map<int, vector<int>> ids;

void solve(SparseTable& st) {
    int m;
    cin >> m;
    vector<long long> p(m);
    long long ans = 0;
    vector<int> wtf;
    for (auto &u : p) {
        cin >> u;
        --u;
        wtf.emplace_back(u);
    }

    int ptr = 0;
    ptr = 0;
    p.emplace_back(n);
    auto solve = [&](long long mx, int ind) {
        int y = last_big[ind];
        y += y != -1;
        long long before = ptr;
        before -= lower_bound(wtf.begin(), wtf.end(), y) - wtf.begin();
        before++;
        before = max(1LL, before);
        y = nxt_big[ind];
        long long after = (lower_bound(wtf.begin(), wtf.end(), y) - wtf.begin()) - (y != mx);
        after -= ptr;
        after += mx == a[p[ptr]];
        dbg(mx,ind,before, after);
        ans += before * after * mx;
    };
    while (ptr < m) {
        long long mx = st.query(p[ptr], p[ptr+1]-1);
        int id = lower_bound(ids[mx].begin(), ids[mx].end(), p[ptr]) - ids[mx].begin();
        id = ids[mx][id];
        solve(a[p[ptr]], p[ptr]);
        if (a[p[ptr]] != mx) {
            solve(mx, id);
        }
        ptr++;
    }
    cout << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    a.assign(n,0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        ids[a[i]].emplace_back(i);
    }
    auto calc = [&](bool rev) {
        vector<int> now(n);
        for (int i = 0; i < n; i++) {
            now[i] = rev ? a[n-1-i] : a[i];
        }
        vector<int> ans(n,rev ? -1 : n);
        vector<int> stk;
        auto comp = [&](int l, int r) {
            if (rev) return l <= r;
            return l < r;
        };
        for (int i = 0; i < n; i++) {
            while (!stk.empty() && comp(now[stk.back()], now[i])) {
                ans[rev ? n-1-stk.back() : stk.back()] = rev ? n - 1 - i : i;
                stk.pop_back();
            }
            stk.emplace_back(i);
        }
        return ans;
    };
    nxt_big = calc(false);
    last_big = calc(true);
    dbg(nxt_big, last_big);
    SparseTable st(a);
    int tt;
    cin >> tt;
    while (tt--) {
        solve(st);
    }
}






