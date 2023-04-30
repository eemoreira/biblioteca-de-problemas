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
vector<set<int>> floors(1005);
vector<int> op(1005, 1e9);

void solve(){
  int n,k;
  cin >> n >> k;
  vector<int> b(n),c(n);
  for(auto &u : b) cin >> u;
  for(auto &u : c) cin >> u;
  vector<pair<int,int>> ord(n+1);
  int mx = 0;
  for(int i = 1; i <= n; i++){
    dbg(op[b[i-1]]);
    ord[i] = {op[b[i-1]],c[i-1]};
    mx += op[b[i-1]];
  }
  dbg(ord);
  int ans = 0;
  vector<vector<int>> dp(mx+1, vector<int>(n+1));
  for(int i = 0; i <= mx; i++){
    for(int j = 1; j <= n; j++){
      dp[i][j] = max(dp[i][j-1], dp[i][j]);
      if(ord[j].first <= i){
        dp[i][j] = max(dp[i][j-1], dp[i-ord[j].first][j-1] + ord[j].second);
      }
    }
  }
  k = min(k,mx);
  cout << dp[k][n] << '\n';
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt;
  cin >> tt;
  op[1] = 0;
  for(int i = 0; i < 1005; i++){
    for(int j = i; j && i + i/j < 1005; j--){
      op[i + i/j] = min(op[i]+1, op[i + i/j]);
    }
  }
  while(tt--){
    solve();
  }
}




