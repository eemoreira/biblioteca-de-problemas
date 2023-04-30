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

string s;
int n;
int solve(int& id) {
  int ans = 0;
  while (true) {
    int now = 0;
    dbg(id);
    id++;
    if (s[id] == '(') {
      now = solve(id);
      id++;
    }
    else {
      id++;
    }
    if (id >= n || s[id] == ')') {
      return max(ans,now);
    }
    if (id < n-1 && s[id++] == '-' && s[id++] == '>') {
      ans = max(now+1, ans);
    }
  }
  return ans;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> s;
  n = s.size();
  int i = 0;
  cout << solve(i) << '\n';
}



