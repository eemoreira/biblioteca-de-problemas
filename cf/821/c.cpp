#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef priority_queue<int, vi, greater<int>> pqg;
#define mp make_pair
#define fst first
#define snd second
#define all(x) begin(x), end(x)
#define sor(x) sort(all(x)) 
#define pb push_back
#define eb emplace_back

int ok2321 = 1;

void solve(){
    int n; cin >> n;
    vi a(n);
    for(auto&u:a)cin>>u;
    int ok = 1;
    for(int i = 1; i < n; i++) ok &= (a[i-1] <= a[i]);
    if(ok){
        cout << 0 << endl;
        return;
    }
    vector<ii> res;
    res.pb(ii(1,n));
    int us = ((a[0]+a[n-1])&1 ? a[0] : a[n-1]);
    swap(a[0],a[n-1]);
    int m = 1;
    for(int i = 1; i < n-1; i++){
        if(a[i] == us) continue;
        m++;
        if((us+a[i])&1) res.pb(ii(1,i+1));
        else res.pb(ii(i+1,n));
    }
    cout << m << endl;
    for(auto u : res) cout << u.fst << ' ' << u.snd << endl;

}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int tc=1;
	if(ok2321) cin >> tc;
    while(tc--) solve();
	return 0;
}



