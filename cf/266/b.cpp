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
  long long n,a,b;
  cin >> n >> a >> b;
  long long need = 6*n;
  if(a*b >= need){
    cout << a*b << '\n';
    cout << a << ' ' << b << '\n';
  }
  else{
    pair<long long, long long> ans;
    long long mi = 1e18;
    for(long long i = min(a,b); i*i <= 6*n; i++){
      long long now = (need + i - 1)/i;
      if(now < max(a,b)){
        continue;
      }
      long long m = now*i - need;
      if(m < mi){
        if(a < b) ans = {min(i,now), max(i,now)};
        else ans = {max(i,now),min(i,now)}; 
        mi = m;
      }
    }
    cout << ans.first*ans.second << '\n';
    cout << ans.first << ' ' << ans.second << '\n';
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
}



