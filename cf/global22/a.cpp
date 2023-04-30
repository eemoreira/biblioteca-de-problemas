#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef priority_queue<ll , vector<ll>, greater<ll>> pqg;
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
    vector<ll> a(n);
    for(auto&u:a)cin>>u;
    vector<ll> fire,fro;
    for(int i = 0; i < n; i++){
        ll u; cin >> u;
        if(!a[i]) fire.pb(u);
        else fro.pb(u);
    }
    if(fire.size() == 0){
        ll b = 0;
        for(auto u : fro) b += u;
        cout << b << endl;
        return;
    }
    if(fro.size() == 0){
        ll b=0;
        for(auto u : fire) b += u;
        cout << b << endl;
        return;
    }
    sor(fire); sor(fro);
    reverse(all(fire)); reverse(all(fro));
    ll ans1=0;
    int mi = min(fire.size(), fro.size());
    for(int i = 0; i < mi; i++){
        ans1 += 2*fire[i] + 2*fro[i];
    }
    for(int i = mi; i < fire.size(); i++) ans1 += fire[i];
    for(int i = mi; i < fro.size(); i++) ans1 += fro[i];
    if(fire.size() == fro.size()) ans1 -= min(fire[fire.size()-1], fro[fro.size()-1]);
    cout << ans1 << endl;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int tc=1;
	if(ok2321) cin >> tc;
    while(tc--) solve();
	return 0;
}



