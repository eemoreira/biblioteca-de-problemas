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

bool isp(int n){
  for(int i = 2; i*i <= n; i++){
    if(n%i==0){
      return false;
    }
  }
  return true;
}

void solve(){
  map<int,int> good;
  good[1] = good[4] = good[6] = good[8] = good[9] = 1;
  int n;
  cin >> n;
  string s;
  cin >> s;
  for(auto u : s){
    if(good[u-'0']){
      cout << 1 << '\n' << u << '\n';
      return;
    }
  }
  for(int i = 0; i < n; i++){
    for(int j = i+1; j < n; j++){
      int num = (s[i]-'0')*10 + s[j] - '0';
      if(!isp(num)){
        cout << 2 << '\n' << num << '\n';
        return;
      }
    }
  }
  assert(false);
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



