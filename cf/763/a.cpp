#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef priority_queue<ii, vector<ii>, greater<ii>> pqg;

int ok2321 = 1;

void solve(){
    int n,m,x,y,xd,yd; cin >> n >> m >> x >> y >> xd >> yd;
    int ans = 1e9;
    if(x == xd || y == yd){
        cout << 0 << endl;
        return;
    }
    if(x - xd < 0) ans = min(ans, xd-x);
    else ans = min(ans, n-x + n-xd);

    if(y - yd < 0) ans = min(ans, yd-y);
    else ans = min(ans, m-y + m-yd);

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



