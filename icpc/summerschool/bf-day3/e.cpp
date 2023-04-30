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
  string s;
  cin >> s;
  vector<vector<long long>> dp(n, vector<long long>(4, 1e18));
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  string h = "hard";
  dp[0][0] = s[0] == 'h' ? a[0] : 0;
  dp[0][1] = 0;
  dp[0][2] = 0;
  dp[0][3] = 0;
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < 4; j++) {
      dp[i][j] = min(dp[i][j], dp[i-1][j]);
      if (s[i] == h[j]) {
        dp[i][j] = dp[i-1][j] + a[i];
      }
      if (j > 0) {
        dp[i][j] = min(dp[i][j-1], dp[i][j]);
      }
    }
  }
  cout << dp[n-1][3] << '\n';
}




