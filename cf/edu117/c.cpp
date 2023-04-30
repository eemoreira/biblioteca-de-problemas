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
  long long k,x;
  cin >> k >> x;
  long long l = 1, r = k;
  long long ans = k;
  while (l <= r) {
    long long mid = (l+r)>>1;
    long long msg = mid * (mid + 1)/2LL;
    if (msg >= x) {
      r = mid - 1;
      ans = mid;
    }
    else {
      l = mid + 1;
    }
  }
  if (ans == k) {
    l = 0;
    r = k-1;
    dbg(ans);
    long long msg = ans * (ans+1)/2;
    ans = 2*k-1;
    long long all = r * (r+1)/2;
    while (l <= r) {
      long long mid = (l+r)>>1;
      long long cur = k - 1 - mid;
      long long sum = msg + all - cur*(cur+1)/2;
      dbg(mid,sum);
      if (sum >= x) {
        ans = k + mid;
        r = mid - 1;
      }
      else {
        l = mid + 1;
      }
    }
  }
  dbg(ans, 2*k-1, ans*(ans+1)/2 < x, x);
  if (ans < 2*k-1 && ans*(ans+1)/2 < x) {
    ans++;
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



