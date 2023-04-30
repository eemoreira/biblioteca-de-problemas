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
  auto Ask = [&](int n) {
    cout << "- " << n << endl;
    cout.flush();
    int ans;
    cin >> ans;
    return ans;
  };
  int cnt;
  cin >> cnt;
  int bit = 1;
  int ans = 0;
  int fliped = 0;
  int last = 0;
  vector<int> fl(30);
  for (int i = 0; i < 30; i++) {
    if (cnt == fliped) {
      break;
    }
    int newcnt = Ask(bit);
    if (newcnt == cnt-1) {
      ans |= bit;
      bit <<= 1;
    }
    else {
      fliped += newcnt-cnt+1;
      bit <<= newcnt-cnt+1;
      ans |= bit;
    }
    dbg(ans);
    cnt = newcnt;
  }
  cout << "! " << ans << endl;
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



