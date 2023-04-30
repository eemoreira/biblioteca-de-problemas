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

int ok2321 = 0;

void solve(){
    ll n; cin >> n;
    vector<ll> a;
    for(ll i = (1ll<<60) - 1; i>=0; i--){
        cout << i << ' ' << n << ' ' << (i&n) << endl;
        i&=n;
        a.pb(i);
    }
    for(int i = a.size()-1; i>=0; i--) cout << a[i] << endl;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int tc=1;
	if(ok2321) cin >> tc;
    while(tc--) solve();
	return 0;
}



