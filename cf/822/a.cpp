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
    int res = 1e9;
    for(int i = 0; i < n; i++){
        int me = 1e9, me2 = 1e9, ind=-1;
        for(int k = 0; k < n; k++){
            if(k==i)continue;
            if(abs(a[i]-a[k]) < me) ind = k;
            me = min(abs(a[i]-a[k]),me); 
        }
        for(int k = 0; k < n; k++){
            if(k==i || k==ind)continue;
            me2 = min(abs(a[i]-a[k]),me2);
        }
        res = min(me+me2,res);
    }
    cout << res << endl;


}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int tc=1;
	if(ok2321) cin >> tc;
    while(tc--) solve();
	return 0;
}



