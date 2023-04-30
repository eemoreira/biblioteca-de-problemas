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
    int n; cin >> n;
    vi a(n);
    for(auto &u : a) cin >> u;
    vi spell(n);
    for(auto &u: spell) cin >> u;
    int ma = -1e9;
    int ind = 0;
    for(int i = 0; i < n; i++){
        if(spell[i] > ma){
            ma = spell[i];
            ind = i;
        }
    }
    ll ans = a[ind];
    if(ind != 0) ans += a[0] + spell[0];
    if(ind != n-1) ans += a[n-1] + spell[n-1];
    for(int i = 1; i < n-1; i++){
        if(i==ind)continue;
        ans += (ll) (a[i] + spell[i]);
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
