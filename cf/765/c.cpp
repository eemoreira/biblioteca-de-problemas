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

int ok2321 = 0;
ll dp[505][505];

void solve(){
    int n,l,k; cin >> n >> l >> k;
    vi a(n);
    for(auto &u : a) cin >> u;
    vi sp(n);
    for(auto &u : sp) cin >> u;
    dp[0][0] = 0;
    for(int i = 1; i <= n; i++){
        for(int d = 0; d <= k; d++){
            dp[i][d] = 1e17 + 5;
        }
    }
    a.pb(l);
    sp.pb(0);
    for(int i = 1; i <= n; i++){
        for(int d = 0; d <= k; d++){
            for(int last = 0; last < i; last++){ // last sign im not removing, and will remove at most k signs before this one
                int beforelast = d - (i - last - 1); //amount to remove before the sign im NOT removing
                if(beforelast >= 0) dp[i][d] = min(dp[i][d], dp[last][beforelast] + (a[i] - a[last]) * sp[last]);
            }
        }
    }
    /* for(int i = 1; i <= n; i++){ */
    /*     for(int d = 0; d <= k; d++){ */
    /*         cout << dp[i][d] << ' '; */
    /*     } */
    /*     cout << endl; */
    /* } */
    ll mi = 1e17;
    for(int i = 0; i <= k; i++) mi = min(mi, dp[n][i]);
    cout << mi << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tc=1;
    if(ok2321) cin >> tc;
    while(tc--) solve();
    return 0;
}



