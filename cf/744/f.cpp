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
  int n,d;
  cin >> n >> d;
  vector<int> a(n);
  for (auto &u : a) {
    cin >> u;
  }
  vector<int> vis(n);
  vector<int> go;
  function<void(int)> Dfs = [&](int v) {
    vis[v] = 1;
    int u = (v+d)%n;
    if (!vis[u]) {
      Dfs(u);
    }
    go.emplace_back(a[v]);
  };
  vector<vector<int>> cyc;
  for (int i = 0; i < n; i++) {
    if(!vis[i]) {
      go.clear();
      Dfs(i);
      reverse(go.begin(), go.end());
      cyc.emplace_back(go);
    }
  }
  dbg(cyc);
  bool ok = true;
  int ans = 0;
  for (auto u : cyc) {
    bool flag = true;
    for (auto x : u) {
      flag &= x;
    }
    if (flag) {
      cout << -1 << '\n';
      return;
    }
    int p = 0;
    int ma = 0;
    bool stop = false;
    dbg(u);
    while (p < (int)u.size() && !stop) {
      int cnt = 0;
      dbg(p);
      while (u[p]) {
        p++;
        if (p >= (int)u.size()) {
          stop = true;
          p %= (int)u.size();
        }
        cnt++;
      }
      p++;
      ma = max(ma,cnt);
    }
    ans = max(ans,ma);
  }
  cout << ans << '\n';
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



