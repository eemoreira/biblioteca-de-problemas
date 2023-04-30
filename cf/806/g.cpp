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
const int mx = 1e5 + 5;
ll a[mx];


void solve(){
    ll k; int n; cin >> n >> k;
    ll ma = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        ma = max(ma,a[i]);
    }
    ll ans = 0;
    vll p(n+1);
    p[0] = 0;
    for(int i = 1; i <= n; i++) p[i] = p[i-1] + a[i-1] - k;
    for(int i = 0; i <= n; i++){
        ll anss = p[i];
        int c = 1;
        for(int d = i; d < n; d++){
            anss += a[d] / (1 << c);
            if(ma / (1 << c) == 0) break;
            c++;
        }
        ans = max(anss,ans);
    }
    cout << ans << '\n';
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tc=1;
    if(ok2321) cin >> tc;
    while(tc--) solve();
    return 0;
}



