#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;

void solve(){
    string s; cin >> s;
    int n = 0;
    for(auto u : s) n += (u=='N');
    cout << (n==1 ? "NO\n" : "YES\n");
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int tc; cin >> tc;
    while(tc--)
    solve();
	return 0;
}

