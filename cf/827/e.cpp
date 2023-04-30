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
    int n,q; cin >> n >> q;
    vector<ll> a(n+1),pref(n+1);
    for(int i = 0; i < n; i++) cin >> a[i];
    pref[0] = 0;
    for(int i = 1; i <= n; i++){
        pref[i] = pref[i-1] + a[i-1];
    }
    vector<ll> mx(n+1);
    mx[0] = 0;
    for(int i = 1; i <= n; i++){
        mx[i] = max(mx[i-1], a[i-1]);
        /* cout << mx[i] << ' '; */
    }
    /* cout << endl; */
    while(q--){
        ll leg; cin >> leg;
        ll ind;
        ind = upper_bound(all(mx) , leg) - mx.begin();
        cout << pref[ind-1] << ' ';
    }
    cout << endl;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int tc=1;
	if(ok2321) cin >> tc;
    while(tc--) solve();
	return 0;
}



