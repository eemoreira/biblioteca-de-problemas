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
const int LOG = 30;

void solve(){
    int n; cin >> n;
    vi a(n),b(n);
    for(auto &u : a) cin >> u;
    for(auto &u : b) cin >> u;
    auto check = [&](int l){
        map<int,int> have;
        for(auto u : a){
            have[u&l]++;
            /* cout << "normal: " << u << ' ' << (u&l) << '\n'; */
        }
        for(auto u : b){
            have[~u&l]--;
            /* cout << "u: " << u << " l: " << l << "nao u??: " << (~u) << " bomba: " << (~u&l) << '\n'; */
        }
        bool ok = true;
        for(auto u : have) ok &= (u.snd == 0);
        return ok;
    };
    int ans = 0;
    for(int i = 30; i >= 0; i--){
        if(check(ans | (1<<i))){
            ans |= (1<<i);
        }
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



