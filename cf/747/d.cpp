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
  int n,m;
  cin >> n >> m;
  map<string, int> mp;
  mp["crewmate"] = 0;
  mp["imposter"] = 1;
  vector<vector<pair<int,int>>> adj(n);
  for (int i = 0; i < m; i++) {
    int u,v;
    cin >> u >> v;
    --u; --v;
    string s;
    cin >> s;
    adj[u].emplace_back(v, mp[s]);
    adj[v].emplace_back(u, mp[s]);
  }
  bool ok = true;
  vector<int> who(n,-1);
  int wch[2];
  function<void(int)> Dfs = [&](int v) {
    wch[who[v]]++;
    for (auto [u,w] : adj[v]) {
      if (who[u] == -1) {
        who[u] = w ^ who[v];
        Dfs(u);
      }
      else if (who[u] != (w ^ who[v])) {
        ok = false;
        return;
      }
    }
  };
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (who[i] == -1) {
      wch[0] = wch[1] = 0;
      who[i] = 0;
      Dfs(i);
      ans += max(wch[1], wch[0]);
    }
  }
  cout << (ok ? ans : -1 ) << '\n';
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



