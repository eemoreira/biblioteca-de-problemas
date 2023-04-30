#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;

void solve(){
    ll a,b,c; cin >> a >> b >> c;
    ll r1 = a-1;
    ll r2 = abs(b-c) + c-1;
    cout << (r1==r2 ? 3 : (r1 < r2 ? 1 : 2)) << endl; 
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int tc; cin >> tc;
    while(tc--)
    solve();
	return 0;
}

