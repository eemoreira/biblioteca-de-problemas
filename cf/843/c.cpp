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
  long long n, x;
  cin >> n >> x;
  if(n == x){
    cout << n << '\n';
    return;
  }
  auto n2 = [&](long long b){
    long long t = 1;
    while(t <= b) t <<= 1;
    return t;
  };
  if(x == 0){
    cout << n2(n) << '\n';
    return;
  }
  vector<int> bitx(64), bitn(64);
  for(int i = 0; i < 64; i++){
    if(x&(1ll<<i)){
      bitx[i]++;
    }
    if(n&(1ll<<i)){
      bitn[i]++;
    }
  }
  int fs = 0;
  for(int i = 0; i < 63; i++){
    if(!bitn[i] && bitx[i]){
      cout << -1 << '\n';
      return;
    }
  }
  for(int i = 63; ~i ; i--){
    if(bitx[i] != bitn[i]){
      fs = i;
      break;
    }
  }
  for(int i = 0; i < fs; i++){
    if(bitx[i] == 1){
      cout << -1 << '\n';
      return;
    }
  }
  dbg(fs,bitx,bitn);
  for(int i = 0; i <= fs; i++) bitn[i] = 0;
  for(int i = fs+1; i < 63; i++){
    bitn[i] ^= 1;
    if(bitn[i]){
      bitn[i] = 1;
      break;
    }
  }
  dbg(fs,bitx,bitn);
  long long ans = 0;
  for(int i = 0; i < 63; i++){
    if(bitn[i]){
      ans |= (1ll << i);
    }
  }
  cout << ((ans & n) == x ? ans : -1) << '\n';
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



