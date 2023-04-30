#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
typedef long long ll;
typedef vector<ll> vll;
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
vi adj[mx];
int score[mx];
vector<pair<ll,ll>> dp[mx];

ll go(int v, ll k){
    for(auto u : dp[v]) if(u.fst == k) return u.snd;
    ll ans = k * score[v];
    if((int)adj[v].size() == 0){
        /* cout << "leaf: " << v << " -> " << ans << '\n'; */
        return ans;
    }
    int cnt = 0;
    if(k % (int)adj[v].size() == 0){
        for(auto u : adj[v]){
            ans += go(u, k / (int)adj[v].size());
        }
    }
    else{
        int sz = (int)adj[v].size();
        ll dpp[sz], dpp2[sz];
        ll difs[sz];
        for(auto u : adj[v]){
            dpp[cnt] = go(u, k/(int)adj[v].size());
            dpp2[cnt] = go(u, k/(int)adj[v].size() + 1);
            cnt++;
        }
        for(int i = 0; i < cnt; i++){
            ans += dpp[i];
            difs[i] = dpp2[i] - dpp[i];
        }
        sort(difs, difs + cnt);
        reverse(difs, difs + cnt);
        for(int i = 0; i < k%cnt;  i++){
            ans += difs[i];
        }
        /* if(v == 1){ */
        /*     cout << v << ": difs -> "; */
        /*     for(int i = 0; i < cnt; i++) cout << difs[i] << ' '; */
        /*     cout << '\n'; */
        /* } */
    }
    /* cout << v << ": ans now: " << ans << '\n'; */
    dp[v].eb(k,ans);
    return ans;
}

void solve(){
    int n; ll k; cin >> n >> k;
    for(int i = 0; i <= n; i++){
        dp[i].clear();
        adj[i].clear();
    }
    for(int i = 2; i <= n; i++){
        int p; cin >> p;
        adj[p].pb(i);
    }
    for(int i = 1; i <= n; i++) cin >> score[i];
    cout << go(1,k) << '\n';
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int tc=1;
	if(ok2321) cin >> tc;
    while(tc--) solve();
	return 0;
}



