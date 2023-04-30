#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
typedef long long ll;

const int mx = 505;

void solve(){
    int n,m;cin>>n>>m;
    vector<string> a(n);
    int b[mx][mx];
    int uns=0;
    for(auto& u : a) cin >> u;
    for(int i = 0; i < n; i++)
        for(int k = 0; k < m; k++){
            b[i][k] = (int)a[i][k] - '0';
            if(b[i][k])uns++;
    }
    int mz=0;
    for(int i = 0; i < n-1; i++)
        for(int k = 0; k < m-1;k++){
            mz = max(mz,!b[i][k] + !b[i+1][k] + !b[i][k+1] + !b[i+1][k+1]);
    }
    if(mz==0)uns-=2;
    else if(mz==1)uns-=1;
    cout << uns << endl;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int tc; cin >> tc;
    while(tc--)
    solve();
	return 0;
}

