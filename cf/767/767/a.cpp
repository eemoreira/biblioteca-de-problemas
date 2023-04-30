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
  int n;
  cin >> n;
  vector<int> a(n), f(n+1);
  int mex = n+1;
  for(auto &u : a){
    cin >> u;
    f[u]++;
  }
  for(int i = 0; i <= n; i++){
    if(!f[i]){
      mex = i;
      break;
    }
  }
  vector<int> b;
  int ptr = 0;
  int nxt = mex; 
  /* dbg(mex); */
  while(ptr < n){
    set<int> s;
    for(int i = ptr; i < n; i++){
      if(a[i] < mex){
        s.emplace(a[i]);
      }
      f[a[i]]--;
      if(!f[a[i]]){
        nxt = min(nxt, a[i]);
      }
      ptr = i;
      if((int)s.size() == mex) break;
    }
    ptr++;
    b.emplace_back(s.size());
    mex = nxt;
  }
  cout << b.size() << '\n';
  for(auto u : b){
    cout << u << ' ';
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



