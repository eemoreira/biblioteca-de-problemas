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
      if(n/i <= 26){
        ps.emplace_back(i);
      }
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
    for(char i = 'a'; i <= 'z';i++){
      if(f[i-'a'] < u){
        a.emplace_back(f[i-'a'],i);
      }
    }
    deque<char> dq;
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
    char now = q.front();
    vector<vector<int>> pos(26);
    for(int i = 0; i < n; i++){
      pos[ans[i]-'a'].emplace_back(i);
    }
    string ord = "";
    for(int i = 0; i < 26; i++){
      if(f[i]){
        ord += char(i+'a');
      }
    }
    sort(ord.begin(), ord.end(), [&](char c, char b){ return f[c-'a'] > f[b-'a'];});
    for(auto x : ord) dq.push_back(x);
    while(!dq.empty()){
      char t = dq.front();
      char b = dq.back();
      if(f[t-'a'] == u){
        dq.pop_front();
        continue;
      }
      if(f[b-'a']==0){
        dq.pop_back();
        continue;
      }
      int r = f[b-'a'];
      for(int i = r-1; ~i; i--){
        if(f[t-'a'] == u){
          dq.pop_front();
          break;
        }
        ans[pos[b-'a'][i]] = t;
        f[t-'a']++;
        f[b-'a']--;
      }
    }
    dbg(ans,ord);
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




