#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;

const int maxn = 1e7 + 5;

int divi[maxn];
void crivo() {
    for (int i = 1; i < maxn; i++) divi[i] = 1;
    for (int i = 2; i < maxn; i++) if (divi[i] == 1) {
        for (int j = i; j < maxn; j+=i) {
            divi[j] = i;
        }
    }
}

void factorize(vector<int>& a, int n) {
    if (n != divi[n]) factorize(a, n / divi[n]);;
    a.emplace_back(divi[n]);
}

bool vis[maxn];
void solve() {
    int n, m;
    cin >> m >> n;
    crivo();
    set<int> v;
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        vector<int> f;
        factorize(f, x);
        for (auto u : f) v.emplace(u);
    }
    v.erase(1);
    ll ans = n;
    for (auto u : v) if (!vis[u]) {
        for (int i = u; i <= n; i += u) {
            if (!vis[i]) {
                vis[i] = 1;
                ans--;
            }
        }
    }
    cout << ans << '\n';
}

int main() {
    cout.sync_with_stdio(0);
    cin.tie(0);
    solve();
}

