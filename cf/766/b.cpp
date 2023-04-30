#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
typedef long long ll;

void solve(){
    int n,m; cin >> n >> m;
    vector<int> ans;
    for(int i = 1; i <= n; i++){
        for(int k = 1;k <= m; k++){
            int mesq = max(i+k-2,abs(i-n)+k-1);
            int mdir = max(abs(i-n)+abs(k-m), abs(k-m)+i-1);
            int maior= max(mdir,mesq);
            ans.push_back(maior);
        }
    }
    sort(ans.begin(),ans.end());
    for(auto u : ans) cout << u << ' ';
    cout << endl;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int tc; cin >> tc;
    while(tc--)
    solve();
	return 0;
}

