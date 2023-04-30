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

void solve(){
    int n,m; cin >> n >> m;
    vi ifc(m);
    for(auto &u : ifc) cin >> u;
    sor(ifc);
    vi rg;
    for(int i = 0; i < (int)ifc.size()-1; i++){
        rg.pb(ifc[i+1] - ifc[i] - 1);
    }
    rg.pb(n - ifc[(int)ifc.size()-1] + ifc[0] - 1);
    /* for(auto u : rg) cout << u << ' '; */
    /* cout << endl; */
    sor(rg);
    reverse(all(rg));
    int dif = 0;
    ll ans = 0;
    for(int i = 0; i < (int)rg.size(); i++){
        /* cout << rg[i] << ' ' << dif + 2 << ' ' << ans << endl; */
        if(rg[i] >= dif + 2) ans += rg[i] - dif - 1;
        else if(rg[i] == dif + 1) ans++;
        else break;
        dif += 4;
    }
    cout << n - ans << endl;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int tc=1;
	if(ok2321) cin >> tc;
    while(tc--) solve();
	return 0;
}



