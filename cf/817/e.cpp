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
const int mx = 1e3 + 5;

void solve(){
    ll a[mx][mx];
    ll pref[mx][mx];
    for(int i = 0; i < mx; i++){
        for(int k = 0; k < mx; k++){
            a[i][k] = pref[i][k] = 0;
        }
    }
    int n,q; cin >> n >> q;
    for(int i = 0 ; i < n ; i++){
        ll x,y; cin >> x >> y;
        a[x][y] += x*y;
    }
    for(int i = 1 ; i < mx ; i++){
        for(int k = 1 ; k < mx; k++){
            pref[i][k] = pref[i-1][k] + pref[i][k-1] - pref[i-1][k-1] + a[i][k];
        }
    }
    while(q--){
        ll hi,wi,hf,wf; cin >> hi >> wi >> hf >> wf;
        /* cout << pref[hf-1][wf-1] << ' ' << pref[hi][wi] << ' '; */
        /* cout << hf-1 << ' ' << wf-1 << ' ' << hi << ' ' << wi << ' '; */
        cout << pref[hf-1][wf-1] - pref[hf-1][wi] - pref[hi][wf-1] + pref[hi][wi] << endl;
    }
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int tc=1;
	if(ok2321) cin >> tc;
    while(tc--) solve();
	return 0;
}



