#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
typedef long long ll;

void solve(){
    int n,m; cin>>n>>m;
    string ans = "Burenka";
    if(n==m){
        cout << "Tonya" << endl;
        return;
    }
    if((m%2==0 && n%2==0) || (m%2 && n%2)){
        cout << "Tonya" << endl;
        return;
    }
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

