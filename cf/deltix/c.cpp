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
vector<bool> isp(1000100);

namespace sieve {
  const int MAX = 1e6 + 10;
  int lp[MAX+1], factor[MAX+1];
  vector <int> pr;
  void build() {
    for (int i = 2; i <= MAX; ++i) {
      if (lp[i] == 0) {
        lp[i] = i;
        pr.push_back(i);
      }
      for (int j = 0; i * pr[j] <= MAX; ++j) {
        lp[i * pr[j]] = pr[j];
        factor[i * pr[j]] = i;
        if (pr[j] == lp[i]) break;
      }
    }
    for(auto u : pr){
      isp[u] = true;
    }
  }
  vector<int> factorize(int x) {
    if (x < 2) return {};
    vector <int> v;
    for (int lpx = lp[x]; x >= lpx; x = factor[x]) v.emplace_back(lp[x]);
      return v;
  }
}

void solve(){
  int n,e;
  cin >> n >> e;
  vector<int> a(n);
  for(auto &u : a){
    cin >> u;
  }
  vector<long long> l(e);
  auto nxt = [&](int it){
    it += e;
    for(;it < n; it+=e){
      if(a[it] != 1){
        return it;
      }
    }
    return it;
  };
  long long ans = 0;
  for(int i = 0; i < n; i++){
    if(isp[a[i]]){
      int p = nxt(i);
      dbg(i,a[i], p);
      dbg(l);
      ans += (long long)l[i%e]*(1 + (p - i - e)/e);
      ans += (long long)(p - i - e)/e;
      l[i%e] = 0;
    }
    else if(a[i] == 1){
      l[i%e]++;
    }
    else{
      l[i%e] = 0;
    }
    dbg(ans);
  }
  cout << ans << '\n';
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt;
  cin >> tt;
  sieve::build();
  while(tt--){
    solve();
  }
}



