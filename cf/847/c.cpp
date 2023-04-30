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
  vector<vector<int>> f(n, vector<int>(n));
  for (int i = 0 ; i < n; i++) {
    for(int j = 0; j < n-1; j++){
      int a;
      cin >> a;
      --a;
      f[a][j]++;
    }
  }
  vector<int> ans(n);
  for (int i = 0; i < n; i++) {
    if (f[i][0] == n-1) {
      ans[0] = i;
      break;
    }
  }
  dbg(ans[0]);
  for (int i = 0; i < n-1; i++) {
    for (int j = 0; j < n; j++) {
      if (f[j][i] && j != ans[i]) {
        ans[i+1] = j;
        break;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    cout << ans[i]+1 << " \n"[i == n-1];
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



