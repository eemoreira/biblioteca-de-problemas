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
    vector<ll> a(n);
    for(auto &u : a) cin >> u;
    if(n == 2){
        cout << 0 << endl;
        return;
    }
    vector<ll> dif; 
    ll ans = 0;
    ll ma = -1e9 - 5;
    for(int i = 1; i < n; i++){
        ans += abs(a[i-1]-a[i]);
    }
    for(int i = 1; i < n-1; i++){
        ma = max(ma, abs(a[i-1]-a[i]) + abs(a[i+1]-a[i]) - abs(a[i+1]-a[i-1]));
    }
    ma = max(ma, abs(a[0]-a[1]));
    ma = max(ma, abs(a[n-1] - a[n-2]));
    cout << ans - ma << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tc=1;
    if(ok2321) cin >> tc;
    while(tc--) solve();
    return 0;
}



