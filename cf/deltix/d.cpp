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
const int N = 1010;
int parent[N];
int sz[N];

void ms(int v){
  parent[v] = v;
  sz[v] = 1;
}


int fs(int v){
  if(v == parent[v]){
    return v;
  }
  return parent[v] = fs(parent[v]);
}

bool unite(int v, int u){
  v = fs(v);
  u = fs(u);
  if(u != v){
    if(sz[v] < sz[u]){
      swap(v,u);
    }
    parent[u] = v;
    sz[v] += sz[u];
    return true;
  }
  return false;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,d;
  cin >> n >> d;
  for(int i = 0; i < n; i++){
    ms(i);
  }
  int k = 0;
  while(d--){
    int u,v;
    cin >> u >> v;
    --u; --v;
    if(!unite(u,v)){
      k++;
    }
    int mx = 0;
    vector<pair<int,int>> m(n);
    for(int j = 0; j < n; j++) m[j] = {sz[j],j};
    sort(m.rbegin(), m.rend());
    vector<int> vis(n);
    dbg(k);
    dbg(m);
    for(int j = 0, cnt = 0; j < n && cnt <= k; j++){
      if(vis[fs(m[j].second)]) continue;
      dbg(j,fs(m[j].second));
      mx += m[j].first;
      cnt++;
      vis[fs(m[j].second)] = 1;
    }
    cout << mx-1 << '\n';
  }
}



