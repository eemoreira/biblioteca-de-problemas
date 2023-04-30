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

struct fenwick{
  vector<int> ft;
  fenwick(int n){
    ft.assign(n + 1,0); // 1 indexed
  }
  int rsq(int i){
    int sum = 0;
    for(; i; i -= (i & -i)){
      sum += ft[i];
    }
    return sum;
  }
  int rsq(int i,int k){
    return rsq(k) - rsq(i-1);
  }
  void update(int i, int v){
    for(; i < (int) ft.size() ; i += (i & -i)){
      ft[i] += v;
    }
  }
};


void solve(){
  int n,q;
  cin >> n >> q;
  string s;
  cin >> s;
  fenwick fenwodd(n), fenweven(n);
  for(int i = 0; i < n; i++){
    if((i+1)&1){
      fenwodd.update(i+1, s[i] == '+' ? 1 : -1);
    }
    else{
      fenweven.update(i+1, s[i] == '+' ? -1 : 1);
    }
  }
  while(q--){
    int l,r;
    cin >> l >> r;
    int sum = 0;
    sum += fenwodd.rsq(l,r);
    sum += fenweven.rsq(l,r);
    if(l == r){
      cout << 1 << '\n';
      continue;
    }
    if(!sum){
      cout << 0 << '\n';
      continue;
    }
    int ans = 1;
    if(!((r-l+1) & 1)) ans++;
    cout << ans << '\n';
    dbg(sum);
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




