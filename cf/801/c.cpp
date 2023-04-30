#include <bits/stdc++.h>
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
const int mx = 1e3 + 5;
int grid[mx][mx];
ii dp[mx][mx];
int n,m; 


ii go(int i,int k){
    if(i < 0 || k < 0) return ii(-1e9 - 6, 1e9 + 6);
    if(dp[i][k] != ii(-1e9 - 5, 1e9 + 5)) return dp[i][k];
    if(i == 0 && k == 0) return dp[i][k] = ii(grid[i][k], grid[i][k]); 
    int ma = grid[i][k]; 
    int mi = grid[i][k];
    ii up = go(i-1, k);
    ii left = go(i, k-1);
    ma += max(up.fst,left.fst);
    mi += min(up.snd, left.snd); 
    return dp[i][k] = ii(ma,mi);
}

void solve(){
    cin >> n >> m;
    for(int i = 0; i < n; i++) for(int k = 0; k < m; k++){
        cin >> grid[i][k];
        dp[i][k] = ii(-1e9 - 5,1e9 + 5);
    }
    if((n + m - 1)&1){
        cout << "NO\n";
        return;
    }
    cout << (go(n-1,m-1).fst >= 0 && dp[n-1][m-1].snd <= 0 ? "YES\n" : "NO\n");
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc=1;
  if(ok2321) cin >> tc;
  while(tc--) solve();
  return 0;
}


