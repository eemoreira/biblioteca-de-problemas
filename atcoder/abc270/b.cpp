#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef priority_queue<ii, vector<ii>, greater<ii>> pqg;
#define mp make_pair
#define fst first
#define snd second
#define all(x) begin(x), end(x)
#define sor(x) sort(all(x)) 
#define pb push_back
#define eb emplace_back

int ok2321 = 0;

void solve(){
    int x,y,z; cin >> x >> y >> z;
    if(y < 0 && x > 0){
        cout << x << endl;
        return;
    }
    if(y > 0 && x < 0){
        cout << abs(x) << endl;
        return;
    }
    int mr = abs(x-z);
    int resto = abs(mr - y);
    if(x > 0 && x < y){
        cout << x << endl;
        return;
    }
    if(x < 0 && x > y){
        cout << abs(x) << endl;
        return;
    }
    if(x > 0 && x > y){
        int dist=0;
        if(z > y) dist = -1;
        else if(z < 0) dist += abs(2*z) + x;
        else dist = x;
        cout << dist << endl;
        return;
    }
    if(x < 0 && x < y){
        int dist = 0;
        if(z < y) dist = -1;
        else if(z > 0) dist += abs(2*z) + abs(x);
        else dist = abs(x);
        cout << dist << endl;
        return;
    }
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int tc=1;
	if(ok2321) cin >> tc;
    while(tc--) solve();
	return 0;
}



