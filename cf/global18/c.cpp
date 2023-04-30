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
  string a,b;
  cin >> a >> b;
  string s;
  if(a == b){
    cout << "0\n";
    return;
  }
  array<int,4> p = {0,0,0,0};
  for(int i = 0; i < n; i++){
    p[0] += a[i] == '0' && b[i] == '0';
    p[1] += a[i] == '1' && b[i] == '1';
    p[2] += a[i] == '1' && b[i] == '0';
    p[3] += a[i] == '0' && b[i] == '1';
  }
  int ans = 1e9;
  dbg(p);
  if(p[1] == p[0]+1){
    ans = min(ans, 1 + 2*p[0]);
  }
  if(p[2] == p[3]){
    ans = min(ans, 2*p[3]);
  }
  cout << (ans==1e9 ? -1 : ans) << '\n';
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


