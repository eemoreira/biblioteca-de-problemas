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

const int maxn = 2e5 + 5;
int f[4 * maxn];
int a[maxn];
int n, m;

void build(int v, int l, int r) {
    if (l == r) {
        f[v] = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(v << 1, l, mid);
    build(v << 1 | 1, mid + 1, r);
    f[v] = max(f[v << 1], f[v << 1 | 1]);
}

void update(int i, int v, int val, int l, int r) {
    if (l > i || r < i) return;
    if (l == r) {
        f[v] = val;
        return;
    }
    int mid = (l + r) >> 1;
    if (i <= mid) {
        update(i, v << 1, val, l, mid);
    }
    else {
        update(i, v << 1 | 1, val, mid + 1, r);
    }
    f[v] = max(f[v << 1], f[v << 1 | 1]);
}

int query(int v, int l, int r, int lb) {
    if (l > n || r < 1) return 1e9;
    if (l == r) return r;

    int mid = (l + r) >> 1;
    if (f[v << 1] >= lb) {
        return query(v << 1, l, mid, lb);
    }
    return query(v << 1 | 1, mid + 1, r, lb);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    build(1, 1, n);
    while (m--) {
        int x;
        cin >> x;
        if (f[1] < x) {
            cout << 0 << ' ';
            continue;
        }
        int ans = query(1, 1, n, x);
        a[ans] -= x;
        update(ans, 1, a[ans], 1, n);
        cout << ans << ' ';
    }
    cout << '\n';
}





