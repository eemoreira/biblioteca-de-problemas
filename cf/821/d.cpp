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
    ll n,x,y; cin >> n >> x >> y;
    string a,b; cin >> a >> b;
    ll c = 0;
    if(a==b){
        cout << 0 << endl;
        return;
    }
    for(int i = 0; i < n; i++){
        c+= (a[i] != b[i]);
    }
    if(c&1){
        cout << -1 << endl;
        return;
    }
    ll conse=0;
    for(int i = 1; i < n; i++){
        conse += (a[i] != b[i] && a[i-1] != b[i-1]); 
    }   
    if(conse == 1 && c == 2){
        cout << min(x,2*y) << endl;
        return;
    }
    ll ans = c*y/2;
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



