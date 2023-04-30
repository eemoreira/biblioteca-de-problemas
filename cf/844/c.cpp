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
  string s;
  cin >> s;
  vector<int> ps;
  for(int i = 1; i <= n; i++){
    if(n%i==0){
      ps.emplace_back(i);
    }
  }
  dbg(ps.size());
  pair<int,string> anss = {1e9, "aa"};
  for(auto u : ps){
    dbg(u);
    string ans = "";
    vector<pair<int,char>> a;
    vector<int> f(26);
    for(auto l : s) f[l-'a']++;
    string ord = "";
    for(char i = 'a'; i <= 'z';i++){
      ord += i;
      if(f[i-'a'] < u){
        a.emplace_back(f[i-'a'],i);
      }
    }
    sort(a.rbegin(), a.rend());
    queue<char> q;
    for(int i = 0; i < (int)a.size(); i++) q.push(a[i].second);
    for(int i = 0; i < n; i++){
      if(f[s[i]-'a'] > u){
        char now = q.front();
        if(++f[now-'a'] == u){
          q.pop();
        }
        ans += now;
        f[s[i]-'a']--;
      }
      else{
        ans += s[i];
      }
    }
    sort(ord.begin(), ord.end(), [&](char c, char b){ return f[c-'a'] < f[b-'a'];});
    char now = q.front();
    /* dbg(ans); */
    /* dbg(ord); */
    /* dbg(f); */
    /* dbg(now); */
    for(auto x : ord){
      for(int i = 0; i < n; i++){
        if(ans[i] == x && f[x-'a'] && f[x-'a'] < u){
          f[x-'a']--;
          ans[i] = now;
          if(++f[now-'a'] == u){
            q.pop();
            while(!q.empty() && !f[q.front()-'a']){
              q.pop();
            }
            if(!q.empty()){
              now = q.front();
            }
          }
        }
      }
    }
    int nowdif = 0;
    for(int i = 0; i < n; i++){
      nowdif += s[i] != ans[i];
    }
    anss = min(make_pair(nowdif,ans), anss);
  }
  cout << anss.first << '\n' << anss.second << '\n';
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




