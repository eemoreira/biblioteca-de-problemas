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
  vector<vector<int>> a(n, vector<int>(m));
  for (int i = 0; i < n ; i++) {
    for (auto &u : a[i]) {
      cin >> u;
    }
  }
  map<vector<int>, int> f;
  vector<vector<int>> ids;
  for (int i = 0; i < n; i++) {
    vector<int> id(m);
    for (int j = 0; j < m; j++) {
      id[a[i][j]-1] = j+1;
    }
    ids.emplace_back(id);
    while (!id.empty()) {
      f[id]++;
      id.pop_back();
    }
  }
  dbg(ids);
  for (auto u : f) {
    dbg(u.first, u.second);
  }
  for (int i = 0; i < n; i++) {
    int ans = m;
    while (!a[i].empty() && !f[a[i]]) {
      a[i].pop_back();
      ans--;
    }
    cout << ans << ' ';
  }
  cout << '\n';
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



