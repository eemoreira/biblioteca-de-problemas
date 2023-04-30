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
    int n,l; cin >> n >> l;
    vi a(n);
    for(auto&u:a)cin>>u;
    vector<vi> res(n,vi(l));
    for(auto u : res) u.assign(l,0);
    for(int i = 0; i < n; i++){
        int t = a[i];
        int c =0;
        while(t){
            res[i][c] = (t&1);
            t >>= 1;
            c++;
        }
        reverse(all(res[i]));
    }
    vi num(l);
    for(int i = 0; i < l; i++){
        int uns=0,ze=0;
        for(int k = 0; k < n; k++){
            uns+= (res[k][i]==1);
            ze+= (res[k][i]==0);
        }
        if(uns > ze)num[i]=1;
        else num[i]=0;
    }
    int ans=0;
    int pot=1;
    for(int i = l-1; i >= 0; i--){
        ans += num[i]*pot;
        pot*=2;
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



