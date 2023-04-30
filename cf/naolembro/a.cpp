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
  int n,k;
  cin >> n >> k;
  vector<pair<int,int>> ans(n/2);
  if(k != n-1){
    ans[0] = {k, n-1};
    for(int i = 1; i < n/2; i++){
      if(i == k){
        ans[i] = {0, n-1-i};
      }
      else if(n-1-i == k){
        ans[i] = {0,i};
      }
      else{
        ans[i] = {i, n-1-i};
      }
    }
  }
  else{
    if(n <= 4){
      cout << -1 << '\n';
      return;
    }
    ans[0] = {n-1,n-2};
    if(n > 2) ans[1] = {1,3};
    for(int i = 2; i < n/2; i++){
      if(i == 3){
        ans[i] = {n-i-1,0};
      }
      else{
        ans[i] = {i, n-1-i};
      }
    }
  }
  long long s = 0;
  for(auto u : ans){
    cout << u.first << ' ' << u.second << '\n';
  }
}
// 0001, 1110
// 1010 1110 -> 5,7 -> 5
// 0100 0110 -> 2,6 -> 2
// 1000 0010 -> 1,4 -> 0
// 0000 1100 -> 0,3 -> 0

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt;
  cin >> tt;
  while(tt--){
    solve();
  }
}



