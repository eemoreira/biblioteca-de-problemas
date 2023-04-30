#include <bits/stdc++.h>
using namespace std;
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define dbg(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define dbg(x...)
#endif
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

/* stop freaking out pls */

void solve(){
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &u : a) {
    cin >> u;
  }
  vector<vector<int>> Adj(n);
  for (int i = 0; i < n; i++) {
    a[i] += i;
    if (a[i] >= 0 && a[i] < n) {
      Adj[a[i]].emplace_back(i);
    }
  }
  vector<int> s(n);
  int y = n;
  function<void(int)> Dfs = [&](int v) {
    s[v] = 1;
    --y;
    dbg(v);
    for (auto u : Adj[v]) {
      Dfs(u);
      s[v] += s[u];
    }
  };
  for (int i = 0; i < n; i++) {
    if (a[i] < 0 || a[i] >= n) {
      Dfs(i);
    }
  }
  int ptr = 0;
  dbg(s);
  if (s[0] == 0) {
    vector<int> vis(n);
    int x = 0;
    while (!vis[ptr]) {
      x++;
      vis[ptr] = 1;
      ptr = a[ptr];
    }
    cout << 1LL * x * (2*n + 1 - y)  << '\n';
  }
  else {
    long long ans = 0;
    int w = n;
    while (ptr >= 0 && ptr < n) {
      --w;
      ans += 1LL * (2*n + 1 - y - s[ptr]);
      ptr = a[ptr];
    }
    ans += 1LL * w * (2 * n + 1);
    cout << ans << '\n';
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt;
  cin >> tt;
  while(tt--){
    solve();
  }
}



