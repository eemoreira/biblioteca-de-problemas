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
  vector<int> c(m), a(n);
  multiset<pair<int,int>, greater<pair<int,int>>> pq;
  vector<int> f(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    --a[i];
    f[a[i]]++;
  }
  for (int i = 0; i < n; i++) {
    if (f[i]) {
      pq.emplace(f[i], i);
    }
  }
  for (auto &u : c) {
    cin >> u;
  }
  sort(c.rbegin(), c.rend());
  int ans = 0;
  for (int i = 0; i < m; i++) {
    if(pq.empty()) {
      break;
    }
    dbg(pq);
    auto mx = *pq.begin();
    pq.erase(pq.begin());
    if (mx.first >= c[i]) {
      dbg(ans);
      ans += c[i];
      pq.emplace(mx.first-c[i], mx.second);
    }
    else {
      ans += mx.first;
    }
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



