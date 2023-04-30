#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
typedef long long ll;

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    for(auto&u : a) cin >> u;
    sort(begin(a),end(a));
    int ans = -a[0]-a[1]+a[n-1]+a[n-2];
    cout << ans << endl;
    }

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int tc; cin >> tc;
    while(tc--)
    solve();
	return 0;
}

