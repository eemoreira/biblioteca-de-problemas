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

ll dfs(int v, ll cnt){
    if((int)adj[v].size() > 1){
        for(auto u : adj[v]){
            ans[v] = max(cnt, dfs(u, 0);
        }
    }
    else return ans[v] = dfs(adj[v][0], cnt+1);
    return ans[v] = cnt + 1;
}

void solve(){
    int n; cin >> n;
    for(int i = 2; i <= n; i++){
        int a; cin >> a;
        adj[a].pb(i);
    }
    ll anss = 0;
    for(int i = 2; i <= n; i++){
        cout << i << ": " << ans[i] << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tc=1;
    while(tc--) solve();
    return 0;
}



