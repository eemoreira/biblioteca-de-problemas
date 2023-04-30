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
    vector<ll> a(n);
    for(auto&u:a)cin>>u;
    ll ans = -1e15;
    vector<ll> res(n);
    for(int i = 0; i < n; i++){
        ll t = -1e15;
        for(int d = i%k; d < n; d+=k){
            t = max(t, a[d]); 
        }
        res[i] = (t == -1e9 ? a[i] : t);
    }
    for(int i = 0; i <= n-k; i++){
        ll sum = 0;
        for(int d = i; d < i+k; d++){
            /* cout << d << ' ' << res[d] << endl;; */
            /* cout << res[d] << ' '; */
            sum +=res[d]; 
        }
        /* cout << endl; */
        /* cout << sum << endl; */
        ans = max(ans,sum);
    }
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



