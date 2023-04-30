#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
typedef long long ll;

void solve(){
    int n; cin >> n;
    int minx=0,miny=0,maxx=0,maxy=0;
    for(int i = 0; i < n; i++){
        int a,b; cin >> a >> b;
        minx =  min(a,minx);
        maxx = max(a,maxx);
        miny = min(b,miny);
        maxy = max(b,maxy);
}  
    int difx = maxx - minx;
    int dify = maxy - miny;
    cout << 2*(difx + dify) << endl;
}
    
int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tc; cin >> tc;
    while(tc--)
    solve();
	return 0;
}

