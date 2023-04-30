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

/* stop freaking out pls */
void solve() {
  int n,m,d;
  cin >> n >> m >> d;
  int ans = 1e9;
  vector<int> pos(n), a(m);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    --x;
    pos[x] = i;
  }
  for (auto &u : a) {
    cin >> u;
    --u;
  }
  for (int i = 0; i < m-1; i++) {
    if (pos[a[i+1]] < pos[a[i]] || pos[a[i+1]] > pos[a[i]] + d) {
      ans = 0;
    }
    else {
      ans = min(ans, pos[a[i+1]] - pos[a[i]]);
      if (d < n-1) {
        ans = min(ans, d+1 - (pos[a[i+1]] - pos[a[i]]));
      }
    }
  }
  cout << ans << '\n';
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




