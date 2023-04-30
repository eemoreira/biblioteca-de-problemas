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
  int n; cin >> n;
  vector<string> g(n);
  for(auto &u : g) cin >> u;
  int ma = 0;
  int all = 0;
  for(int i = 0; i < n; i++){
    for(auto u : g[i]){
      all += u - '0';
    }
  }
  for(int i = 0; i < 2*n; i++){
    int cnt = 0;
    int cnt1 = 0;
    for(int j = 0; j < n; j++){
      cnt += (g[j%n][(j+i)%n] - '0');
      cnt1 += (g[(j+i)%n][j%n] -'0');
    }
    /* cout << i << ' ' << cnt << ' ' << cnt1 << '\n'; */
    ma = max(max(cnt1,cnt),ma);
  }
  cout << all - ma + n - ma << '\n';
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc=1;
  if(ok2321) cin >> tc;
  while(tc--) solve();
  return 0;
}



