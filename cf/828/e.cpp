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
const int mx = 1e5 + 5;

void solve(){
    ll a,b,c,d; cin >> a >> b >> c >> d;
    ll num = a*b;
    map<ll,int> have;
    have[1] = b+1;
    for(int i = b+1; i <= d; i++){
        have[i] = i;
        for(int k = 2; k <= sqrt(i); k++){
            if(i % k == 0){
                have[k] = i;
                have[i / k] = i;
            }
        }
    }
    for(int i = a+1; i <= c; i++){
        ll common = gcd(num,i);
        ll cur = num / common;
        /* cout << i << ' ' << num << ' ' << common << ' '; */
        /* cout << cur << endl; */
        if(have[cur]){
            cout << i << ' ' << have[cur] << endl;
            return;
        }
    }
    cout << -1 << ' ' << -1 << endl;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int tc=1;
	if(ok2321) cin >> tc;
    while(tc--) solve();
	return 0;
}



