#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
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
const int mx = 1e5 +5;

void solve(){
    int n,q; cin >> n >> q;
    vll a(n);
    for(auto &u : a) cin >> u;
    int l,r; cin >> l >> r;
    vll pf(n+1);
    vll xorf(n+1);
    pf[0] = 0;
    xorf[1] = 0;
    for(int i = 1; i <= n; i++) pf[i] = pf[i-1] + a[i-1];
    for(int i = 1; i <= n; i++) xorf[i] = xorf[i-1] ^ a[i-1];

    ll best = 0;
    for(int i = 0; i <= n; i++){
        best = max(pf[r] - pf[i] - (xorf[r]^xorf[i]),best);
    }
    ii ans = ii(1,n);
    for(int i = 1; i <= n; i++){
        int lf = i, rt = n;
        ii res = ii(1,n);
        /* cout << i << " ------"; */
        while(lf <= rt){
            int mid = (lf+rt)>>1;
            if(pf[mid] - pf[i-1] - (xorf[mid]^xorf[i-1]) == best){
                res = ii(i,mid);
                /* cout << mid << ' ' << res.fst << ' ' << res.snd << '\n'; */
                rt = mid - 1;
            }
            else{
                lf = mid + 1;
            }
        }
        /* cout << res.snd - res.fst << ' ' << ans.snd - ans.fst << '\n'; */
        if(res.snd - res.fst < ans.snd - ans.fst) ans = res;
    }
    cout << ans.fst << ' ' << ans.snd << '\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tc=1;
    if(ok2321) cin >> tc;
    while(tc--) solve();
    return 0;
}



