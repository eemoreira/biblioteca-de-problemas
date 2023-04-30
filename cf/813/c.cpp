#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
typedef long long ll;

const int mx = 2e5 + 5;

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    for(auto& u : a) cin >> u;
    map<int,int> z,mp;
    int pf[mx];
    int res=0,count=0;
    for(int i = 0; i < n; i++){
        if(!mp[a[i]]) count++;
        pf[i] = count;
        mp[a[i]] = 1;
    }
    int id=-1,s=0;
    for(int i = 1; i < n; i++){
        if(a[i] < a[i-1] || z[a[i]]){
            id = i-1;
            for(int k = s; k <= id; k++) z[a[k]] = 1;
            s = id;
        }
    }
    res = id == - 1 ? 0 : pf[id];
    cout << res << endl;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int tc; cin >> tc;
    while(tc--)
    solve();
	return 0;
}


