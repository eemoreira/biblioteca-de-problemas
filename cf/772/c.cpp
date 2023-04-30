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
  vector<long long> a(n);
  for (auto &u : a) {
    cin >> u;
  }
  multiset<pair<long long, int>> pq;
  vector<vector<int>> ans;
  for (int i = n-2; i < n; i++) {
    pq.emplace(a[i],i);
  }
  for (int i = n-3; ~i; i--) {
    if (a[i] <= a[i+1]) {
      pq.emplace(a[i],i);
    }
    else {
      auto tma = *pq.rbegin();
      auto tmi = *pq.begin();
      a[i] = tmi.first - tma.first;
      pq.emplace(a[i],i);
      vector<int> t = {i, min(tma.second,tmi.second), max(tma.second,tmi.second)};
      ans.emplace_back(t);
    }
  }
  dbg(a);
  if (!is_sorted(a.begin(), a.end())) {
    cout << -1 << '\n';
  }
  else {
    cout << ans.size() << '\n';
    for (auto u : ans) {
      for (auto x : u) {
        cout << x+1 << ' ';
      }
      cout << '\n';
    }
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



