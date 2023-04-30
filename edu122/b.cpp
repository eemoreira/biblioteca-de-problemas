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

int solve(string s){
  int fo = -1, fz = -1;
  for(int i = 0; i < (int)s.size(); i++){
    if(fo == -1 && s[i] == '1'){
      fo = i;
    }
    if(fz == -1 && s[i] == '0'){
      fz = i;
    }
  }
  auto check = [&](string a){
    int n = a.size();
    int on = 0;
    for(auto u : a){
      on += u - '0';
    }
    dbg(on, n);
    if(2*on != n){
      return min(on, n-on);
    }
    return 0;
  };
  int ans = check(s);
  if(fo != -1) ans = max(ans,check(s.substr(fo+1)));
  if(fz != -1) ans = max(ans,check(s.substr(fz+1)));
  return ans;
}

void solve(){
  string s;
  cin >> s;
  int ans = 0;
  ans = solve(s);
  reverse(s.begin(), s.end());
  ans = max(ans, solve(s));
  cout << ans << '\n';
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



