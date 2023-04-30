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
int n,m,k;
string g[50];
vector<vector<int>> vis(15,vector<int>(21));

void mark(int x, int y, int d){
  if(x + d >= n || y + 2*d >= m) return;
  int yy = y+2*d; 
  int t = y;
  bool ok = true;
  for(int i = x; i <= x+d; i++){
    if(g[i][t++] == '.' || g[i][yy--] == '.'){
      ok = false;
    }
  }
  if(ok){
    yy = y+2*d;
    for(int i = x; i <= x+d; i++){
      vis[i][y] = vis[i][yy] = true;
      y++;
      yy--;
    }
  }
}

void solve(){
  cin >> n >> m >> k;
  for(int i = 0; i < n; i++){
    cin >> g[i];
  }
  vis.assign(15, vector<int>(21,0));
  for(int i = k; i < n; i++){
    for(int x = 0; x < n; x++){
      for(int y = 0; y < m; y++){
        if(g[x][y] == '*'){
          mark(x,y,i);
        }
      }
    }
  }
  bool ok = true;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      if(g[i][j] == '*'){
        ok &= vis[i][j];
      }
    }
  }
  cout << (ok ? "yes\n" : "no\n");
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



