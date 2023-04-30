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

int ok2321 = 1;

void solve(){
    ll n; cin >> n;
    map<ll,int> mp;
    for(ll i = 0; i < 10*n; i++){
        mp[i*i] = 1;
    }
    int ok = 0;
    vi ans((int)n+1);
    int usin = n-1;
    while(usin){
        if(usin == 2){
            ans[0] = 1;
            ans[1] = 0;
            ans[2] = 2;
            break;
        }
        if(mp[usin]){
            for(int i = 0; i < usin; i++){
                ans[i] = usin-i;
            }
            break;
        }
        int change;
        for(int i = usin-1; i >= 0; i--){
            if(mp[usin+i]){
                change = i-1;
                for(int k = i; k <= usin; k++){
                    ans[k] = usin-(k-i);
                }
            }
        }
        usin = change;
    }
    for(int i = 0; i < n; i++) cout << ans[i] << ' ';
    cout << endl;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int tc=1;
	if(ok2321) cin >> tc;
    while(tc--) solve();
	return 0;
}



