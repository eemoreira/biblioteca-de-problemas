#include <bits/stdc++.h>

using namespace std;

const int mx = 2e5 + 5;
int pf[mx];

void solve(){
    int n,k;cin>>n>>k;
    string s; cin>>s;
    pf[0] = s[0] == 'W' ? 1 : 0;
    for(int i = 1; i <= n; i++){
        pf[i] = pf[i-1];
        if(s[i-1] == 'B') pf[i]++;
    }
    int res = k;
    for(int i = k; i <= n; i++){
        res = min(res, k - (pf[i] - pf[i-k]));
    }
    cout << res << endl;

    
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int t;cin>>t;
    while(t--)
    solve();
	return 0;
}

