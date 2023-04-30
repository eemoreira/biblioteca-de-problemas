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
    int n; cin >> n;
    vi a(n);
    for(auto&u:a)cin>>u;
    map<int,int> freq;
    int ok = 0;
    for(int i = 0; i < n; i++) freq[a[i]]++;
    for(int i = 0; i < n; i++){
        ok |= (freq[a[i]] > 1);
    }
    if(!ok){
        cout << -1 << endl;
        return;
    }
    map<int,vector<int>> mp;
    for(int i = 0; i < n; i++){
        mp[a[i]].pb(i);
    }
    int ans = -1e9;
    for(auto [x,u] : mp){
        if(u.size() <= 1) continue;
        for(int i = 0; i < u.size()-1; i++){
            /* cout << x << ' ' << u[i] << ' ' << u[i+1] << endl; */
            int f = u[i];
            int s = u[i+1];
            ans = max(ans,n - s + f); 
        }
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



