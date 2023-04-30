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
  auto check = [&](long long num){
    long long sq = sqrtl(num);
    while(sq*sq < num) sq++;
    while(sq*sq > num) sq--;
    return sq*sq == num;
  };
  auto getans = [&](long long x, long long y, long long fac, long long d){
    int ans = 0;
    long long f = (d + fac)>>1;
    long long g = f*f - x;
    long long f1 = (d - fac)>>1;
    long long g1 = f1*f1 - y;
    if(x > f*f || f*f - f1*f1 != x - y) return 0;
    assert(g == g1);
    for(int i = 0; i < n; i++){
      if(check(a[i] + g)){
        ans++;
      }
    }
    return ans;
  };
  int ans = 1;
  sort(a.begin(), a.end());
  int g = 0;
  for(int i = 0; i < n; i++){
    g += check(a[i]);
    for(int j = i+1; j < n; j++){
      int dif = a[j] - a[i];
      dbg(dif);
      for(int d = 1; d*d <= dif; d++){
        if(dif%d==0){
          ans = max(ans, getans(a[j], a[i], d, dif/d));
        }
      }
    }
  }
  ans = max(ans,g);
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



