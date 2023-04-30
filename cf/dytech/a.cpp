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
  int n,q; cin >> n >> q;
  string s; cin >> s;
  map<char,int> f;
  for(auto u : s) f[u]++;
  string has = "";
  for(int i = 0; i < q; i++) has += 'a'-1;
  vi sry(q);
  for(char c = 'a'; c <= 'y'; c++){
    for(int i = 0; i < q; i++){
      if(f[c] && sry[i] != n/q){
        f[c]--;
        has[i]++;
        sry[i]++;
      }
      else sry[i] = n/q;
    }
  }
  for(auto u : has) cout << char(u+1);
  cout << '\n';
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc=1;
  if(ok2321) cin >> tc;
  while(tc--) solve();
  return 0;
}



