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
vector<vi> coprime(1005);

void solve(){
    int n; cin >> n;
    vi a(n);
    for(auto &u : a) cin >> u;
    map<int,int> ind, have;
    for(int i = 0; i < n; i++){
        ind[a[i]] = i + 1;
        have[a[i]] = 1;
    }
    int ans = 0;
    set<int> bla;
    for(auto u : a) bla.insert(u);
    for(auto u : bla){
        if(u == 1) ans = max(ind[u]*2, ans);
        for(auto x : coprime[u]){
            if(ind[x]) ans = max(ind[u] + ind[x] , ans);
        }
    }
    cout << (ans == 0 ? -1 : ans) << endl;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int tc=1;
    for(int i = 1; i < 1001; i++){
        for(int k = 1; k < 1001; k++){
            if(gcd(i,k) == 1) coprime[i].pb(k);
        }
    }
	if(ok2321) cin >> tc;
    while(tc--) solve();
	return 0;
}



