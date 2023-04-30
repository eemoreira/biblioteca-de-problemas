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
namespace sieve {
  const int MAX = 3e5 + 5;
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
  }
  vector<int> factorize(int x) {
    if (x < 2) return {};
    vector <int> v;
    for (int lpx = lp[x]; x >= lpx; x = factor[x]) v.emplace_back(lp[x]);
    return v;
  }
}

void solve(){
  int n;
  cin >> n;
  vector<int> a(n);
  map<int, set<int>> who;
  vector<vector<int>> fs(n);
  for(int i = 0; i < n; i++){
    cin >> a[i];
    auto t = sieve::factorize(a[i]);
    for(auto u : t){
      who[u].emplace(i);
    }
    fs[i] = t;
  }
  int x,y;
  cin >> x >> y;
  --x;--y;
  queue<int> q;
  vector<int> d(n,1e9);
  q.emplace(y);
  d[y] = 0;
  for(auto f : fs[y]){
    who[f].erase(y);
  }
  vector<int> ans(n);
  while(!q.empty()){
    int v = q.front();
    q.pop();
    for(auto p : fs[v]){
      while(!who[p].empty()){
        int u = *who[p].begin();
        d[u] = d[v]+1;
        ans[u] = v;
        q.emplace(u);
        for(auto f : fs[u]){
          who[f].erase(u);
        }
      }
    }
  }
  if(d[x] == 1e9){
    cout << -1 << '\n';
    return;
  }
  cout << 1+d[x] << '\n';
  int end = x;
  while(end != y){
    cout << end+1 << ' ';
    end = ans[end];
  }
  cout << y+1 << '\n';
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  sieve::build();
  solve();
}



