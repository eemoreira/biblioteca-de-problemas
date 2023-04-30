#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
typedef long long ll;
typedef vector<int> vi;

void solve(){
    int n,m; cin >> n >> m;
    if(n > m || (m&1 && (n&1)==0)){
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    if(n == 1){
        cout << m << endl;
        return;
    }
    for(int i = 0; i < n-2; i++) cout << 1 << ' ';
    if(n&1){
        cout << 1 << ' ' << m - n + 1<< endl;
    }
    else{
        int resto = m - (n-2);
        cout << resto/2 << ' ' << resto/2 << endl;
    }
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int tc; cin >> tc;
    while(tc--)
    solve();
	return 0;
}

