#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;

void solve(){
    int n; cin >> n;
    vector<int> p,im;
    for(int i = 0; i < n; i++){
        int a; cin >> a;
        if(a&1)im.push_back(a);
        else p.push_back(a);
    }
    for(auto&u:im) cout << u <<  ' ';
    for(auto&u:p) cout << u << ' ';
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

