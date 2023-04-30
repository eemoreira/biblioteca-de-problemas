#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
typedef long long ll;

void solve(){
    int a,b; cin >> a >> b;
    if(a<b)swap(a,b);
    int res=0;
    if(a==b){
        cout << a/2 << endl;
        return;
    }
    if(b - a/3 + a%3 >= 4) res+= (b - a/3 + a%3)/4;
    res += min(a/3, b);
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

