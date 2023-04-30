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
  int n,m;
  cin >> n >> m;
  vector<vector<char>> a(n+2, vector<char>(m+2, '.'));
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= m; j++){
      cin >> a[i][j];
    }
  }
  vector<vector<int>> p(n+1, vector<int>(m+1));
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= m; j++){
      p[i][j] = p[i-1][j] + p[i][j-1] - p[i-1][j-1];
      if(a[i-1][j] != '.' && a[i][j-1] != '.'){
        p[i][j]++;
      }
    }
  }
  dbg(p);
  int q;
  cin >> q;
  while(q--){
    int x1,x2;
    cin >> x1 >> x2;
    int ans = p[n][x2] - p[n][x1] - p[0][x2] + p[0][x1];
    cout << (ans ? "no\n" : "yes\n");
  }
}


