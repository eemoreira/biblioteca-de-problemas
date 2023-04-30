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
#define eb emplace_back

int ok2321 = 0;



void solve(){
    int n; cin >> n;
    vector<ll> res;
    for(int i  = 1; i < n; i++){
        if(gcd(i,n)==1){
            res.pb(i);
        }
    }
    ll prod = 1;
    for(auto u : res){
        prod = (prod*u)%n;
    }
    if(prod%n == 1){
        cout << res.size() << endl;
        for(auto u : res) cout << u << ' ';
        cout << endl;
        return;
    }
    if(prod%n == n-1){
        cout << res.size() - 1 << endl;
        for(int i = 0; i < (int)res.size() - 1; i++) cout << res[i] << ' ';
        cout << endl;
        return;
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



