#
￼
include <bits/stdc++.h>
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
    vector<string> grid(n);
    for(auto &u : grid) cin >> u;
    vi q(n);
    for(int i = 0; i < n; i++){
        for(int k = 0; k < n; k++){
            if(grid[i][k] == '1'){
                q[i]++;
            }
        }
    }
    vii order(n);
    for(int i = 0; i < n; i++) order[i] = ii(q[i],i);
    sor(order);
    reverse(all(order));
    vector<vi> ans(n);
    int cur = 1;
    for(auto [u,w] : order){
        ans[w].pb(cur);
        for(int i = 0; i < n; i++){
            if(grid[w][i] == '1'){
                ans[i].pb(cur);
            }
        }
        cur++;
    }
    for(int i = 0; i < n; i++){
        cout << (int)ans[i].size() << ' ';
        for(auto u : ans[i]) cout << u << ' ';
        cout << '\n';
    }
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc=1;
  if(ok2321) cin >> tc;
  while(tc--) solve();
  return 0;
}



