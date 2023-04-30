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

void solve(){
    int n,q; cin >> n >> q;
    vll a(n);
    for(auto &u : a) cin >> u;
    vll pf(n+1), xorf(n+1);
    for(int i = 1; i <=n ; i++){
        pf[i] = pf[i-1] + a[i-1];
        xorf[i] = xorf[i-1]^a[i-1];
    }
    vi nxtf(n+10), nxtb(n+10);
    for(int i = 0; i < n; i++){
        int it = i;
        if(a[it] == 0 && it == n-1){
            nxtf[it] = it;
            continue;
        }
        while(a[it] == 0 && it < n-1) it++;
        if(it != i) for(int d = i; d < it && d < n; d++) nxtf[d] = it;
        i = it;
    }
    for(int i = n-1; i >= 0; i--){
        int it = i;
        if(a[it] == 0 && it == 0){
            nxtb[it] = it;
            continue;
        }
        while(a[it] == 0 && it > 0) it--;
        if(it != i) for(int d = i; d > it && d >= 0; d--) nxtb[d] = it;
        i = it;
    }
    /* cout << "nxft: "; */
    /* for(int i = 0; i < n; i++) cout << nxtf[i] << ' '; */
    /* cout << '\n'; */
    /* cout << "nxtb: "; */
    /* for(int i = 0; i < n; i++) cout << nxtb[i] << ' '; */
    /* cout << '\n'; */
    while(q--){
        int l,r; cin >> l >> r;
        ll best = pf[r] - pf[l-1] - (xorf[r]^xorf[l-1]);
        if(best==0){
            cout << l << ' ' << l << '\n';
            continue;
        }
        int removed = 0;
        ii ans = ii(l,r);
        for(int i = l; i <= r && removed <= 30; i++){
            if(a[i-1] == 0) i = min(r,nxtf[i-1] + 1);
            removed++;
            int sufrem = 0;
            for(int k = r; k >= i && sufrem <= 30; k--){
                if(a[k-1] == 0) k = max(nxtb[k-1]+1,i);
                sufrem++;
                if(pf[k] - pf[i-1] - (xorf[k]^xorf[i-1]) == best){
                    if(ans.snd - ans.fst > k - i) ans = ii(i,k);
                }
            }
        }
        cout << ans.fst << ' ' << ans.snd << '\n';
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



