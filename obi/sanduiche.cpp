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
const int mx = 405;

void solve(){
    int n,m; cin >> n >> m;
    vector<ii> a;
    for(int i = 0; i < m; i++){
        int aa,b; cin >> aa >> b;
        aa--;
        b--;
        a.eb(aa,b);
    }
    ll ans = 0;
    for(int mask = 1; mask <= (1<<n)-1; mask++){
        bool ok = true;
        vi num;
        int d = mask;
        int cnt = 0;
        cout << "sanduiche: ";
        while(cnt <= 10){
            num.pb((d&(1<<cnt)) != 0);
            cnt++;
        }
        reverse(all(num));
        for(auto u : num) cout << u;
        cout << '\n';
        cout << "ingredientes:\n";
        for(auto u : a){
            cout << u.fst << ' ' << u.snd << '\n';
            if(mask&(1<<u.fst) && mask&(1<<u.snd)) ok = false;
        }
        if(ok) ans++;
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



