#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
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

const int mx = 1e5 + 5;
vi adj[mx];
ll ans[mx];
ll deep[mx];
ll dp[mx];

ll dfs(int v){
    for(auto u : adj[v]){
        deep[v] = max(dfs(u),deep[v]);
    }
    return ++deep[v];
}

ll go(int v){
    if(dp[v] != -1) return dp[v];

    ll gett = 0;
    for(auto u : adj[v]){
        gett += go(u);
    }
    /* cout << v << ' ' << gett << '\n'; */
    return dp[v] = max(deep[v], gett);
}

void solve(){
    int n; cin >> n;
    dp[1] = -1;
    for(int i = 2; i <= n; i++){
        dp[i] = -1;
        int a; cin >> a;
        adj[a].pb(i);
    }
    dfs(1);
    cout << go(1) << '\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tc=1;
    while(tc--) solve();
    return 0;
}



