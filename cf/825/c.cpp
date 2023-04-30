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
    vi a(n);
    for(auto &u : a) cin >> u;
    vi notok;
    int dif = 0;
    int cnt = 0;
    set<ii> res;
    for(int i = 0; i < n ; i++){
        if(a[i] + dif > i) res.insert(ii(cnt,i));
        else{
            dif -= (a[i]+dif-i-1);
            cnt = dif;
            res.insert(ii(cnt,i));
            /* cout << i << ": " << dif << ' ' << cnt << endl; */
        }
    }
    ll ans = 0;
    for(auto u : res){
        /* cout << u.fst << ' ' << u.snd << endl; */
        ans += (u.snd - u.fst + 1);
    }
    cout << ans << endl;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int tc=1;
	if(ok2321) cin >> tc;
    while(tc--) solve();
	return 0;
}



