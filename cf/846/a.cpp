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
  vector<int> c,b;
  vector<int> a(n);
  int od = 0, ev = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i]&1) {
      od++;
    }
    else {
      ev++;
    }
  }
  if (od >= 1 && ev >= 2) {
    cout << "yes\n";
    for (int i = 0; i < n; i++) {
      if (a[i]&1) {
        cout << i+1 << ' ';
        break;
      }
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      if(cnt < 2 && a[i]%2==0) {
        cout << i+1 << ' ';
        cnt++;
      }
    }
    cout << '\n';
  }
  else if(od >= 3) {
    cout << "yes\n";
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      if (cnt < 3 && a[i]%2==1) {
        cout << i+1 << ' ';
        cnt++;
      }
    }
    cout << '\n';
  }
  else {
    cout << "no\n";
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



