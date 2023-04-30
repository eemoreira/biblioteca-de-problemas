#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef priority_queue<ii, vii, greater<ii>> pqmin;
#define mp make_pair
#define fst first
#define snd second
#define all(x) begin(x), end(x)
#define sor(x) sort(all(x)) 
#define pb push_back
#define pf push_front
#define eb emplace_back
#define inf 1e9+5
#define linf 1e17+5

int ok2321 = 1;

void solve(){
  string s; cin >> s;
  int n; cin >> n;
  vector<string> a(n);
  for(auto &u : a) cin >> u;
  vector<vector<string>> have((int)s.size());
  map<string,int> ind;
  for(int i = 0; i < n; i++) ind[a[i]] = i;
  for(int i = 0; i < (int)s.size(); i++){
    for(int j = 0; j < (int)s.size()-i; j++){
      string cur = s.substr(i,j+1);
      for(auto u : a){
        if(cur == u){
          have[i].pb(u);
        }
      }
    }
  }
  for(int i = 0; i < (int)s.size(); i++) sort(all(have[i]), [&](string aa, string bb){return (int)aa.size() > (int)bb.size();});
  vii ans;
  vi vis((int)s.size());
  int last = 0;
  for(int i = 0; i < (int)s.size(); i++){
    int it = i;
    int ma = 0;
    string cur;
    for(int j = i; j <= min((int)s.size()-1,last + (i != 0)); j++){
      if((int)have[j].size()){
        /* cout << have[j][0] << '\n'; */
        if(((int)have[j][0].size()+j-1-last) >= ma){
          it = j;
          cur = have[j][0];
          ma = (int)have[j][0].size()+j-1-last;
        }
      }
    }
    /* cout << it << ' ' << cur << '\n'; */
    for(int j = it; j < it + (int)cur.size(); j++) vis[j] = 1;
    bool db = true;
    ans.eb(ind[cur]+1,it+1);
    for(int j = 0; j < (int)s.size(); j++) db &= vis[j];
    if(db){
      cout << (int)ans.size() << '\n';
      for(auto u : ans) cout << u.fst << ' ' << u.snd << '\n';
      return;
    }
    /* for(int j = 0; j < (int)s.size(); j++) cout << vis[j]; */
    /* cout << '\n'; */
    last = it + (int)cur.size() - 1;
  }
  cout << -1 << '\n';
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc=1;
  if(ok2321) cin >> tc;
  while(tc--) solve();
  return 0;
}



