#include <bits/stdc++.h>
  long long 
#define endl '\n'

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef priority_queue<ii, vii, greater<ii>> pqg;
#define mp make_pair
#define fst first
#define snd second
#define all(x) begin(x), end(x)
#define sor(x) sort(all(x)) 
#define pb push_back
#define pf push_front
#define eb emplace_back

int ok2321 = 1;
const int mx = 4e3 + 5;
vi adj[mx];
ii colors[mx];
int ans;
string s;

ii dfs(int v){
    if(s[v] == 'W') colors[v].fst++;
    else colors[v].snd++;
    for(auto u : adj[v]){
        ii t = dfs(u);
        colors[v].fst += t.fst;
        colors[v].snd += t.snd;
    }
    ans += (colors[v].fst == colors[v].snd);
    return colors[v];
}

void solve(){
    int n; cin >> n;
    ans = 0;
    for(int i = 0; i <= n; i++){
        adj[i].clear();
        colors[i] = ii(0,0);
    }
    for(int i = 1; i < n; i++){
        int p; cin >> p;
        p--;
        adj[p].pb(i);
    }
    cin >> s;
    dfs(0);
    cout << ans << '\n';
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc=1;
  if(ok2321) cin >> tc;
  while(tc--) solve();
  return 0;
}


