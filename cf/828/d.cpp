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
    int no2 = 0;
    vi qnt;
    for(int i = 1; i <= n; i++){
        int t = i;
        int cnt = 0;
        while(t%2==0){
            cnt++;
            t >>= 1;
        }
        qnt.pb(cnt);
    }
    for(int i = 0 ; i < n; i++){
        while(a[i]%2==0){
            a[i] >>= 1;
            no2++;
        }
    }
    ll ans = 0;
    sor(qnt);
    reverse(all(qnt));
    for(auto u : qnt){
        if(no2 >= n){
            cout << ans << endl;
            return;
        }
        no2 += u;
        ans++;
    }
    cout << -1 << endl;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int tc=1;
	if(ok2321) cin >> tc;
    while(tc--) solve();
	return 0;
}



