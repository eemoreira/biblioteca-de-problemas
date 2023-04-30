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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

/* stop freaking out pls */

void solve(){
  int n;
  cin >> n;
  int t = n;
  vector<pair<int,int>> x;
  for (int i = 2; i*i <= n; i++) {
    bool ok = false;
    int cnt = 0;
    while (t%i==0) {
      ok = true;
      t /= i;
      cnt++;
    }
    if (ok) {
      x.emplace_back(cnt,i);
    }
  }
  if (t > 1) {
    x.emplace_back(1,t);
  }
  sort(x.begin(), x.end());
  long long ans = 0;
  int f = x.size();
  for (int i = 0; i < f; i++) {
    int m = x[i].second;
    assert(x[i].first >= 0);
    for (int j = i+1; j < f; j++) {
      m *= x[j].second;
      x[j].first -= x[i].first;
    }
    ans += m * x[i].first;
  }
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



