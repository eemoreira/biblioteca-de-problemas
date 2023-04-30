#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
typedef long long ll;

void solve(){
    int n,m; cin >> n >> m;
    if(n>m) swap(n,m);
    if(n==1 && m==1){
        cout << 0 << endl;
        return;
    }
    int fstdif = n-1;
    cout << m-1 + n + fstdif << endl;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int tc; cin >> tc;
    while(tc--)
    solve();
	return 0;
}

