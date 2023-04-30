#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef priority_queue<ii, vector<ii>, greater<ii>> pqg;

int ok2321 = 1;

void solve(){
    int n;cin>>n;
    vector<ll> x(n),y(n),dif(n);
    for(auto&u:x)cin>>u;
    for(auto&u:y)cin>>u;
    for(int i = 0; i < n; i++)dif[i]=y[i]-x[i];
    sort(dif.begin(),dif.end());
    int s =0, end=n-1;
    int ans = 0;
    vector<int> vis(n);
    vis.assign(n, 0);
    while(s < end){
       if(dif[s]+dif[end] >= 0){
            vis[s] = 1;
            vis[end] = 1;
            s++;end--;ans++;
       }
       else{
           s++;
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

