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
  int a,c;
  cin >> a >> c;
  vector<int> p(n), b(n);
  for (int i = 0; i < a; i++) {
    int v;
    cin >> v;
    --v;
    p[v] = 1;
  }
  for (int i = 0; i < c; i++) {
    int v;
    cin >> v;
    --v;
    b[v] = 1;
  }
  vector<vector<int>> adj(n);
  for (int i = 0; i < m; i++) {
    int u,v;
    cin >> u >> v;
    --u; --v;
    adj[v].emplace_back(u);
    adj[u].emplace_back(v);
  }
  if (p[0]) {
    cout << "yes\n";
    return;
  }
  queue<int> q;
  vector<int> d(n, 1e9);
  d[0] = 0;
  q.emplace(0);
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    for (auto u : adj[v]) {
      if (v == 0 && p[u]) {
        cout << "yes\n";
        return;
      }
      if (d[u] == 1e9) {
        d[u] = d[v] + 1;
        if (b[u]) {
          q.emplace(u);
        }
      }
    }
  }
  if (a == 1) {
    cout << "no\n";
    return;
  }
  vector<int> gt(n);
  for (int i = 0; i < n; i++) {
    for (auto u : adj[i]) {
      if (b[u]) {
        gt[i] = 1;
      }
    }
  }
  int one = 0;
  int two = 0;
  vector<int> IDK1(n), IDK2(n);
  for (int i = 0 ; i < n; i++) {
    if (p[i]) {
      bool t = false;
      one += gt[i];
      IDK1[i] += gt[i];
      for (auto u : adj[i]) {
        if (b[u] && gt[u]) {
          t = true;
        }
      }
      if ((gt[i] && b[i]) || t) {
        two++;
        IDK2[i] = 1;
      }
    }
  }
  for (int i = 0 ; i < n; i++) {
    if (p[i] && d[i] < 1e9) {
      if (two - IDK2[i] > 0) {
        cout << "yes\n";
        return;
      }
      if(one - IDK1[i] >= d[i] - 1) {
        cout << "yes\n";
        return;
      }
    }
  }
  cout << "no\n";
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }
}



