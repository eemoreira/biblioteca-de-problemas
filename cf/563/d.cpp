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
  int n,x;
  cin >> n >> x;
  vector<int> ans;
  for (int i = 1; i < 1 << n; i++) {
    if (i < (i ^ x)) {
      ans.emplace_back(i);
    }
  }
  dbg(ans);
  vector<int> xr;
  if (ans.empty()) {
    cout << 0 << '\n';
    return 0;
  }
  xr.emplace_back(ans[0]);
  for (int i = 1; i < (int)ans.size(); i++) {
    xr.emplace_back(ans[i] ^ ans[i-1]);
  }
  cout << xr.size() << '\n';
  for (int i = 0; i < (int)xr.size(); i++) {
    cout << xr[i] << " \n"[i == (int)xr.size()-1];
  }
}




