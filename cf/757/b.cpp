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
  vector<pair<long long,int>> a(n);
  for(int i = 0; i < n; i++){
    int b;
    cin >> b;
    a[i] = {b,i+1};
  }
  vector<int> ans(n+1);
  ans[0] = 0;
  long long now = 1;
  vector<int> used(n+1);
  sort(a.rbegin(), a.rend());
  long long mx = 0;
  for(int i = 0; i < n; i++){
    if(used[now] == 2) now++;
    if(!used[now]){
      ans[a[i].second] = now;
    }
    if(used[now] == 1){
      ans[a[i].second] = -now;
    }
    mx += a[i].first * now;
    used[now]++;
  }
  cout << 2*mx << '\n';
  for(int i = 0; i <= n; i++){
    cout << ans[i] << " \n"[i==n];
  }
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



