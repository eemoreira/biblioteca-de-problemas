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
  vector<string> a(n);
  map<string,int> f, f2, fsb;
  bool ok = false;
  for(auto &u : a){
    cin >> u;
    f[u]++;
    if((int)u.size() == 2){
      f2[u]++;
    }
    if((int)u.size() == 3){
      fsb[u.substr(1)]++;
    }
  }
  dbg(f);
  for(int i = 0; i < n; i++){
    string t = a[i];
    reverse(t.begin(), t.end());
    ok |= f[t];
    ok |= fsb[t];
    f[a[i]]--;
    if((int)a[i].size() == 2) f2[a[i]]--;
    if((int)a[i].size() == 3){
      string g = a[i].substr(0,2);
      reverse(g.begin(), g.end());
      ok |= f2[g];
      fsb[a[i].substr(1)]--;
    }
  }
  cout << (ok ? "yes\n" : "no\n");
}

// aba

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt;
  cin >> tt;
  while(tt--){
    solve();
  }
}



