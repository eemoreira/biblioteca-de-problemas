#include <bits/stdc++.h>
#define endl '\n'
#define int long long 
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
    int n, k; cin >> n >> k;
    vi pfs(k);
    for(auto&u:pfs)cin>>u;
    int slot = n - k;
    if(k == 1){
        cout << "yes" << endl;
        return;
    }
    int ok = 1;
    int cur = (n==k ? pfs[0] : pfs[1] - pfs[0]);
    if(n==k){
        for(int i = 1; i < k; i++){
            /* cout << cur << ' ' << pfs[i] << ' ' << pfs[i-1] << endl; */
            ok &= (cur <= pfs[i]-pfs[i-1]);
            cur = pfs[i] - pfs[i-1];
        } 
        if(ok) cout << "yes" << endl;
        else cout << "no" << endl;
        return;
    }
    for(int i = 2; i < k; i++){
        /* cout << cur << ' ' << pfs[i] << ' ' << pfs[i-1] << endl; */
        ok &= (cur <= pfs[i]-pfs[i-1]);
        cur = pfs[i] - pfs[i-1];
    } 
    if(!ok){
        cout << "no" << endl;
        return;
    }
    else{
        int slots = n-k+1;
        if(slots*(pfs[1]-pfs[0]) >= pfs[0]){
            cout << "yes" << endl;
        }
        else{
            cout << "no" << endl;
            return;
        }
    }
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int tc=1;
	if(ok2321) cin >> tc;
    while(tc--) solve();
	return 0;
}



