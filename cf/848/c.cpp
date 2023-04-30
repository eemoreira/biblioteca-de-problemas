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
  int n,q;
  cin >> n >> q;
  string s,t;
  cin >> s >> t;
  vector<int> f(26);
  for (int i = 0; i < n; i++) {
    if (s[i] != t[i]) {
      f[s[i]-'a'] = 1;
    }
  }
  int r = 0;
  for (int i = 0; i < 26; i++) {
    r += f[i];
  }
  if (r <= q) {
    cout << 1LL * n * (n+1)/2 << '\n';
    return;
  }
  long long ans = 0;
  vector<int> g(26,-1);
  int p = 0;
  for (int i = 0; i < 26; i++) {
    if (f[i]) {
      g[i] = p++;
    }
  }
  auto go = [&](int mask) {
    if (__builtin_popcount(mask) != q) return 0LL;
    string u = s;
    for (int i = 0; i < n; i++) {
      if (g[s[i]-'a'] != -1 && mask >> g[s[i]-'a'] & 1) {
        u[i] = t[i];
      }
    }
    long long ret = 0;
    for (int i = 0; i < n; i++) {
      int ptr = i;
      while (i < n && u[i] == t[i]) {
        i++;
      }
      for (int j = ptr; j < i; j++) {
        ret += i - j;
      }
    }
    return ret;
  };
  for (int i = 0; i < 1 << r; i++) {
    ans = max(ans, go(i));
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




