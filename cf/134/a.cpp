#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
typedef long long ll;

void solve(){
    vector<char> c(4);
    map<int,int> tem;
    for(int i = 0; i < 4; i++){
        cin >> c[i];
        tem[c[i]]++;
    }
    int m=0;
    int um=0,dois=0,tres=0,quatro=0;
    for(auto u : tem){
        if(u.second == 1) um++;
        if(u.second == 2) dois++;
        if(u.second == 3) tres++;
        if(u.second == 4) quatro++;
    }
    int ans=0;
    if(um==3 || um==4) ans=3;
    else if(dois==1) ans = 2;
    else if(dois==2 || tres==1) ans = 1;
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

