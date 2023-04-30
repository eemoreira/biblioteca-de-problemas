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
const int MAX = 2e5 + 5;
vector<int> adj[MAX];
int op[MAX], d[MAX];
bool mask[MAX];

int brute(int mx, int x) {
  int ans = mx;
  queue<int> q;
  d[x] = 0;
  q.emplace(x);
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    if (mask[v]) {
      ans = min(ans, d[v]);
    }
    for (auto u : adj[v]) {
      if (d[v] + 1 < d[u] && d[v] + 1 < mx) {
        d[u] = d[v] + 1;
        q.emplace(u);
      }
    }
  }
  return ans;
}

void solve(){
  int n, x;
  cin >> n >> x;
  --x;
  for (int i = 0; i < n; i++) {
    adj[i].clear();
    op[i] = 0;
    mask[i] = 0;
    d[i] = 1e9;
  }
  mask[x] = true;
  for (int i = 0; i < n-1; i++) {
    cin >> op[i];
    --op[i];
  }
  for (int i = 1; i < n; i++) {
    int u,v;
    cin >> u >> v;
    --u; --v;
    adj[u].emplace_back(v);
    adj[v].emplace_back(u);
  }
  int mi = 1e9;
  for (int i = 0; i < n-1; i++) {
    mi = min(mi, d[op[i]]);
    mi = min(mi,brute(mi, op[i]));
    cout << mi << ' ';
    mask[op[i]] = true;
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



