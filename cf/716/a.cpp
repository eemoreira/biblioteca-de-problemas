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

map<ll,int> tem;
    
void solve(){
    int n; cin >> n;
    vi a(n);
    for(auto&u:a)cin>>u;
    vector<vi> f(n);
    for(int i = 0; i < n; i++){
        int d = 2;
        while(a[i] > 1){
            if(a[i]%d){
                d++;
                continue;
            }
            f[i].pb(d);
            a[i]/=d;
        }
        /* for(auto u : f[i]) cout << u << ' '; */
        /* cout << endl; */
    }
    
    for(int i = 0; i < n; i++){
        int ok = 0;
        map<int,int> freq;
        for(auto u : f[i]) freq[u]++;
        for(auto [u,w] : freq) ok |= (w&1);
        if(ok){
            cout << "YES" << endl;
            return;
        }
        for(int k = 0; k < n; k++){
            if(k==i)continue;
            if(ok){
                cout << "YES" << endl;
                return;
            }
            for(auto u : f[k]) freq[u]++;  
        }
    }

    cout << "NO" << endl;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

    int tc=1;
	if(ok2321) cin >> tc;
    while(tc--) solve();
	return 0;
}



