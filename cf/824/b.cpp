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
    for(auto&u:a)cin >> u;
    int mi = 1e9;
    int ind;
    for(int i = 0; i < n ;i++){
        if(a[i]< mi){
            mi = a[i];
            ind = i;
        }
    }
    ll ans = 0;
    for(int i = 0; i < n; i++){
        if(i == ind)continue;
        if(a[i] < 2*mi)continue;
        ans  += a[i]/(2*mi-1);
        if(a[i]%(2*mi-1)==0) ans--;
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



