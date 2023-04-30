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

vector<long long> f, sub;
vector<pair<long long, int>> all;
int sz;

void solve(){
  long long n;
  cin >> n;
  int ans = 1e9;
  int ptr = 0;
  while(ptr < (int)all.size() && all[ptr].first <= n){
    auto u = all[ptr];
    int bits = 0;
    long long num = n - u.first;
    while(num){
      if(num&1){
        bits++;
      }
      num >>= 1;
    }
    ans = min(ans, bits + u.second);
    ptr++;
  }
  cout << ans << '\n';
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  long long fat = 1;
  for(int i = 1; fat < 1e12 + 30; i++){
    fat *= i;
    f.emplace_back(fat);
  }
  sz = f.size();
  for(int msk = 0; msk < (1 << sz); msk++){
    int mask = msk;
    long long sum = 0;
    int bits = 0;
    for(int j = 0; j < sz; j++){
      if(mask & (1 << j)){
        sum += f[j];
        bits++;
      }
    }
    all.emplace_back(sum, bits);
  }
  sort(all.begin(), all.end());
  int tt;
  cin >> tt;
  while(tt--){
    solve();
  }
}



