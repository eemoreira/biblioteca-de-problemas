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
void solve() {
  int n;
  long long h;
  cin >> n >> h;
  vector<long long> a(n);
  for (auto &u : a) {
    cin >> u;
  }
  long long l = 1, r = h+1;
  auto check = [&](long long mid) {
    vector<pair<long long, long long>> p;
    int ptr = 0;
    while (ptr < n) {
      int j = ptr;
      for (int i = ptr; i < n-1; i++) {
        j = i+1;
        if (a[i] + mid - 1 < a[i+1]) {
          j--;
          break;
        }
      }
      p.emplace_back(a[ptr],a[j]);
      ptr = j+1;
    }
    long long ans = 0;
    for (auto u : p) {
      ans += u.second + mid - u.first;
    }
    dbg(ans, p, mid, h);
    return ans >= h;
  };
  long long ans = h;
  while (l <= r) {
    long long mid = (l+r) >> 1;
    if (check(mid)) {
      r = mid - 1;
      ans = mid;
    }
    else {
      l = mid + 1;
    }
  }
  cout << ans << '\n';
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }
}




