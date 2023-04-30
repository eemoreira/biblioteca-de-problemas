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
  string s;
  cin >> s;
  int n = s.size();
  int fb = -1;
  for(int i = 1; i < n-1; i++){
    if(s[i] == 'a'){
      for(int j = 0; j < i; j++) cout << s[j];
      cout << " a ";
      for(int j = i+1; j < n; j++) cout << s[j];
      cout << '\n';
      return;
    }
  }
  if(s[0] == 'a'){
    if(s[n-1] == 'b'){
      for(int i = 0; i < n-2; i++)cout << s[i];
      cout << ' ' << s[n-2] << ' ' << s[n-1] << '\n';
    }
    else{
      cout << s[0] << ' ';
      for(int i = 1; i < n-1; i++) cout << s[i];
      cout << ' ' << s[n-1] << '\n';
    }
    return;
  }
  cout << s[0] << ' ' << s[1] << ' ';
  for(int i = 2; i < n; i++) cout << s[i];
  cout << '\n';
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



