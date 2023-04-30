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
    int n,c; cin >> n >> c;
    vi a(n);
    for(auto &u : a) cin >> u;
    int ans = 1e9;
    int ok = 1;
    for(auto u : a){
        ok &= (c > u);
    }
    if(n == 1 || ok){
        cout << 0 << endl;
        return;
    }
    int cntt = 0;
    for(int i = a[0]; cntt < sqrt(a[0]) ; i--){
        vi pi(n);
        cntt++;
        if(i == 0){
            for(auto &u : pi) u = c;
        }
        for(int k = 0; k < n; k++){
            pi[k] = min(c, a[k]/i);
        }
        /* cerr << "v: " << i << endl; */
        /* cerr << "pi: "; */
        /* for(auto u : pi) cout << u << ' '; */
        /* cout << endl; */
        int ma = 0;
        /* cerr << "division:" << endl; */
        for(int k = 0 ; k < n; k++){
            /* cerr << a[k] << "/" << pi[k] << ": " <<  a[k]/pi[k] << endl; */
            ma = max(ma, a[k]/pi[k] - i);
        }
        /* cout << "dif maxima com min: " << ma << endl; */
        ans = min(ans,ma);
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




