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
    for(auto & u : a) cin >>u;
    vi zeros;
    for(int i = 0 ; i < n; i++) if(!a[i]) zeros.pb(i);
    if((int) zeros.size() == 0 || (int) zeros.size() == n){
        cout << 0 << endl;
        return;
    }
    int t = zeros.size()-1;
    int ans = 0;
    for(int i = 0; i < n; i++){
        cout << i << ' ' << zeros[t] << endl;
        if(i >= zeros[t]) break;
        if(a[i]){
            ans++;
            if(t==0)break;
            t--;
        }
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



