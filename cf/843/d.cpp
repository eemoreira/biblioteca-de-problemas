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

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  int ma = 0;
  vector<int> a(n);
  for(int i = 0; i < n; i++){
    cin >> a[i];
    ma = max(ma,a[i]);
  }
  int x,y;
  cin >> x >> y;
  --x;--y;
  if(x == y){
    cout << "1\n" << 1+x << '\n';
    return 0;
  }
  if(gcd(a[x],a[y]) != 1){
    cout << "2\n";
    cout << x+1 << ' ' << y+1 << '\n';
    return 0;
  }
  set<int> dog, num;
  vector<int> gt(ma+5);
  for(int i = 0; i < n; i++){
    gt[a[i]] = i;
  }
  for(int i = 0; i < n; i++) if(i != x) dog.emplace(a[i]);
  num.emplace(a[x]);
  int cnt = 0;
  bool ok = false;
  vector<vector<int>> adj(n+5);
  while(!dog.empty()){
    set<int> remove;
    bool found = false;
    for(auto u : dog){
      for(auto d : num){
        if(gcd(u,d) != 1){
          dbg(u,d);
          found = true;
          if(u == a[y]) ok = true;
          adj[gt[d]].emplace_back(gt[u]);
          remove.emplace(u);
        }
      }
    }
    for(auto u : remove){
      dog.erase(u);
      num.emplace(u);
    }
    if(!found || ok){
      break;
    }
  }
  queue<int> q;
  vector<int> d(n+1, 1e9);
  d[x] = 0;
  q.push(x);
  dbg(adj);
  while(!q.empty()){
    int v = q.front();
    dbg(v,adj[v]);
    q.pop();
    for(auto u : adj[v]){
      dbg(u);
      d[u] = min(d[u], d[v]+1);
      q.push(u);
    }
  }
  dbg(d,y);
  cout << (ok ? 1+d[y] : -1) << '\n';
  if(ok){
    vector<int> can(n+1);
    int s = x;
    cout << x+1 << ' ';
    while(s != y){
      pair<int,int> mi = {1e9,1e9};
      bool stop = false;
      for(auto u : adj[s]){
        if(u==y) stop = true;
        if(!(int)adj[u].size()) continue;
        mi = min(mi, pair<int,int>(d[u], u));
      }
      if(stop)break;
      cout << mi.second+1 << ' ';
      s = mi.second;
    }
    cout << y+1 << '\n';
  }
}



