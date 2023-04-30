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

int ok2321 = 0;

void solve(){
    int n,m; cin >> n >> m;
    vi a(m);
    map<int,int> freq;
    for(auto&u:a)cin>>u;
    int qnts=0;
    for(auto u : a){
        freq[u]++;
        if(freq[u] == 1)qnts++;
        if(qnts == n){
            cout << 1;
            qnts = 0;
            for(int i = 1; i <= n; i++){
                freq[i]--;
                if(freq[i])qnts++;
            }
        }
        else cout << 0;
    }
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



