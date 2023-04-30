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

void solve(){
  int n,m;
  cin >> n >> m;
  vector<int> a(n);
  vector<vector<int>> fac;
  for (auto &u : a) {
    cin >> u;
  }
  dbg(fac);
  vector<int> f(m+1);
  sort(a.begin(), a.end());
  for (auto u : a) {
    vector<int> t;
    for (int i = 1; i*i <= u; i++) {
      if (u%i==0) {
        t.emplace_back(i);
        t.emplace_back(u/i);
      }
    }
    fac.emplace_back(t);
  }
  int have = 0;
  auto Add = [&](int id) {
    for (auto u : fac[id]) {
      if (u <= m) {
        if (!f[u]) {
          have++;
        }
        f[u]++;
      }
    }
  };
  auto Mns = [&](int id) {
    for (auto u : fac[id]) {
      if (u <= m) {
        f[u]--;
        if (!f[u]) {
          have--;
        }
      }
    }
  };
  int ans = 1e9;
  int l = 0, r = 0;
  while (l < n || r < n) {
    dbg(l,r,have);
    while (have < m && r < n) {
      Add(r++);
      dbg(r,have);
    }
    if (have == m) {
      ans = min(ans, a[r-1]-a[l]);
    }
    Mns(l);
    l++;
  }
  cout << (ans == 1e9 ? -1 : ans) << '\n';
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



