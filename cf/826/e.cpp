#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef priority_queue<ii, vector<ii>, greater<ii>> pqg;
#define mp make_pair
#define fst first
#define snd second
#define all(x) begin(x), end(x)
#define sor(x) sort(all(x)) 
#define pb push_back
#define pf push_front
#define eb emplace_back

int ok2321 = 1;
const int mx = 2e5 + 5;
set<int> adj[mx];
int n;
int dp[mx];

bool dfs(int v){
    if(dp[v] != -1) return dp[v];
    if(v == n-1 && (int)adj[v].size()) return dp[v] = true;
    dp[v] = 0;
    for(auto u : adj[v]){
        if(u==n-1) return dp[u] = true;
        if(dp[n-1] != 1) dp[v] |= dfs(u+1);
    }
    return dp[v];
}

void solve(){
    cin >> n;
    for(int i = 0; i < n; i++){
        adj[i].clear();
        dp[i] = -1;
    }
    vi a(n);
    for(auto &u : a) cin >> u;
    for(int i = 0; i < n; i++){
        if(a[i] + i < n) adj[i].insert(a[i]+i);
        if(i - a[i] >= 0) adj[i-a[i]].insert(i);
    }
    /* for(int i = 0; i < n; i++){ */
    /*     cout << i << ": "; */
    /*     for(auto u : adj[i]) cout << u << ' '; */
    /*     cout << '\n'; */
    /* } */
    dp[0] = dfs(0);
    cout << (dp[n-1]==1 ? "yes\n" : "no\n");
    /* for(int i = 0; i < n; i++) cout << dp[i] << ' '; */
    /* cout << '\n'; */
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tc=1;
    if(ok2321) cin >> tc;
    while(tc--) solve();
    return 0;
}



