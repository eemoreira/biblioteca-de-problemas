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
int n;
ll f[maxn], a[maxn];

void update(int i, ll v) {
    while (i <= n) {
        f[i] += v;
        i += i & -i;
    }
}

ll query(int i) {
    ll ans = 0;
    while (i) {
        ans += f[i];
        i -= i & -i;
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        update(i, i);
        update(i + 1, -i);
    }
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        int y = query(x);
        int ans = 0;
        int l = 1, r = n;
        while (l <= r) {
            int mid = (l + r)
        }
        cout << a[y] << " \n"[i == n - 1];
        update(y, -1);
    }
}





