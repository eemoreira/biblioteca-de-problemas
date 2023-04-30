#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef priority_queue<ii, vector<ii>, greater<ii>> pqg;

int ok2321 = 1;

const int mx = 1005;

vector<vector<ii>> adj(mx);
vector<ii> r(mx);
int n;

void dfs(int low, int high){
    if(low == high){
        cout << low << ' ' << low << ' ' << low << endl;
        return;
    }
    if(high < low) return;

    int mi = 1e9;
    int ma = -mi;
    for(int i = 0; i < n; i++){
        if(r[i].first == low && r[i].second==high) continue;
        if(r[i].first == low && r[i].second < high){
            ma = max(r[i].second,ma);
        }
        if(r[i].second == high && r[i].first > low){
            mi = min(r[i].first,mi);
        }
    }
    int res;
    if(ma==mi)res=ma;
    else if(ma==-1e9)res=low;
    else if(mi==1e9)res=high;
    else res = ma+1;
    cout << low << ' ' << high << ' ' << res << endl;
    dfs(low,ma),dfs(mi,high);
}


void solve(){
    cin >> n;
    map<ii,int> tem;
    for(auto u : adj) u.clear();
    r.clear();
    for(int i = 0; i < n; i++){
        int a,b; cin >> a >> b;
        r[i] = ii(a,b);
    }
    dfs(1,n);
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



