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
#define eb emplace_back

int ok2321 = 1;

void solve(){
    int n,k; cin >> n >> k;
    vi a(n),b(n);
    int keep = k;
    for(auto&u:a)cin>>u;
    for(auto&u:b)cin>>u;
    int ans = -1e9;
    vector<vi> adj(1005);
    for(int i = 0; i < n; i++){
        adj[a[i]].pb(b[i]);
    }
    vi vis(1005);
    for(auto u : vis) u = 0;
    sor(a);
    for(int i = 0; i < n; i++){
        if(k < a[i] || vis[a[i]]) continue;
        for(auto u : adj[a[i]]){ 
            k += u;
        }
        vis[a[i]] = 1;
        ans = max(k,ans);
    }
    if(ans == -1e9) ans = keep; 
    cout << ans << endl;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int tc=1;
	if(ok2321) cin >> tc;
    while(tc--) solve();
	return 0;
}



