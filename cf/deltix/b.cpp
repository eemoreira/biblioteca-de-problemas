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
  int n,q;
  cin >> n >> q;
  string s;
  cin >> s;
  int cnt = 0;
  for(int i = 0; i < n-2; i++){
    cnt += (s.substr(i,3) == "abc");
  } 
  auto check = [&](int x){
    return x >= 0 && x < n-2 && s[x] == 'a' && s[x+1] == 'b' && s[x+2] == 'c';
  };
  while(q--){
    int i;
    char c;
    cin >> i >> c;
    --i;
    cnt -= check(i);
    cnt -= check(i-1);
    cnt -= check(i-2);
    s[i] = c;
    cnt += check(i);
    cnt += check(i-1);
    cnt += check(i-2);
    cout << cnt << '\n';
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
}



