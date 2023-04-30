#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
typedef long long ll;
typedef vector<int> vi;

void solve(){
    int n; cin >> n;
    vi a(n);
    for(auto&u:a)cin>>u;
    int res=0;
    int maior=0,menor=1e9;
    for(int i = 1; i < n; i++){
        maior = max(maior,a[i]);
    }
    for(int i = 0; i < n-1; i++){
        menor = min(menor,a[i]);
    }
    res = max(a[n-1] - menor,max(maior-a[0],res));
    for(int i = 1; i < n; i++){
        res = max(a[i-1] - a[i],res);
    }
    cout << res << endl;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int tc; cin >> tc;
    while(tc--) solve();
	return 0;
}

