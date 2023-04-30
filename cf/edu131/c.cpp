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
    vi a(m);
    vi have(n+1);
    for(int i = 0; i < m; i++){
        cin >> a[i];
        have[a[i]]++;
    }
    int l = 1, r = 2*m;
    int ans = 0;
    while(l <= r){
        int mid = (l+r)/2;
        ll notcp = 0, cp = 0;
        /* cerr << "mid: " << mid << endl; */
        for(int u = 1; u <= n; u++){
            /* cout << "u: " << u << endl; */
            /* cerr << "cp: " << min(mid,have[u]) + ((mid - min(mid,have[u]))/2) << endl; */
            /* cerr << "notcp: " << have[u] - min(mid,have[u]) << endl; */
            cp += min(mid,have[u]) + ((mid-min(mid,have[u]))/2);
            notcp += have[u] - min(mid,have[u]);
        }
        if(cp > notcp && cp >= m){
            ans = mid;
            r = mid - 1;
        }
        else l = mid + 1;
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



