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
  vector<long long> a(n);
  for(auto &u : a){
    cin >> u;
  }
  vector<vector<long long>> dp(n+1, vector<long long>(n+1,-1e9));
  for(int i = 0; i <= n; i++){
    dp[i][0] = 0;
  }
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= i; j++){
      dp[i][j] = max(dp[i-1][j], dp[i][j]);
      if(dp[i-1][j-1] >= 0){
        dp[i][j] = max(dp[i][j], dp[i-1][j-1] + a[i-1]);
      }
    }
  }
  int ans = 0;
  for(int i = 0; i <= n; i++){
    if(dp[n][i] >= 0){
      ans = i;
    }
  }
  cout << ans << '\n';
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
}



