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

int ok2321 = 0;

void solve(){
    int n,q; cin >> n >> q;
    vi a(n);
    for(auto &u : a) cin >> u;
    vi xorf(n+1);
    vll pf(n+1);
    for(int i = 1; i <= n; i++) xorf[i] = xorf[i-1]^a[i-1], pf[i] = pf[i-1] + a[i-1];
    map<int,int> even,odd; 
    vi where(n+1,-1);
    even[0] = 0;
    for(int i = 1; i <= n; i++){
        if(i&1){
            if(even.count(xorf[i])){
                where[i] = even[xorf[i]];
            }
            odd[xorf[i]] = i;
        }
        else{
            if(odd.count(xorf[i])){
                where[i] = odd[xorf[i]];
            }
            even[xorf[i]] = i;
        }
    }
    while(q--){
        int l,r; cin >> l >> r;
        int range = r - l + 1;
        if(pf[r] - pf[l-1] == 0) cout << 0 << '\n';
        else if(xorf[r]^xorf[l-1]) cout << -1 << '\n';
        else{
            if(range&1) cout << 1 << '\n';
            else{
                if(a[l-1] == 0 || a[r-1] == 0) cout << 1 << '\n';
                else if(where[r] >= l) cout << 2 << '\n';
                else cout << -1 << '\n';
            }
        }
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



