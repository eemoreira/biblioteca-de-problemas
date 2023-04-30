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
    int n,q ; cin >> n >> q;
    vector<ll> a(n);
    for(auto & u: a) cin >> u;
    int eve = 0, odd =0;
    ll ans = 0;
    for(auto u : a){
        ans += u;
        if(u&1) odd++;
        else eve++;
    }
    while(q--){
        ll d,num; cin >> d >> num;
        if(d&1){
            ans += (num * odd);
            if(num&1){
                eve += odd;
                odd = 0;
            }
        }
        else{
            ans += (num * eve);
            if(num&1){
                odd += eve;
                eve = 0;
            }
        }
        cout << ans << endl;
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



