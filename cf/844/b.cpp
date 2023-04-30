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
  vector<int> cnt(n);
  vector<int> f(n);
  for(int i = 0; i < n; i++){
    cin >> cnt[i];
    f[cnt[i]]++;
  }
  int ans = 0;
  set<int> s;
  for(auto u : cnt) s.emplace(u);
  cnt.clear();
  for(auto u : s) cnt.emplace_back(u);
  for(int i = 0; i < n-1; i++){
    f[i+1] += f[i];
  }
  n = cnt.size();
  int ptr = 0;
  dbg(cnt);
  dbg(f);
  while(ptr < n){
    for(int i = ptr; i < n; i++){
      ptr = i;
      if(i < n-1 && f[cnt[i]] > cnt[i] && f[cnt[i]] < cnt[i+1]){
        break;
      }
    }
    ptr++;
    ans++;
  }
  if(cnt[0] != 0) ans++;
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



