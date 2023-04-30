#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
typedef long long ll;

const int mx = 2e5 + 5;

void solve(){
    int n; cin >> n;
    map<int, int> mp;
    int sizetodif=0;
    for(int i = 0; i < n; i++){
        int a; cin >> a;
        if(mp[a]) sizetodif = max(sizetodif, mp[a]);
        mp[a] = i+1;
    }
    cout << sizetodif << endl;
    

}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
	int t; cin >> t;
    while(t--)
    solve();
	return 0;
}

