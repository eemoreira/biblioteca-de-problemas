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

int ok2321 = 1;

void solve(){
    int n,m; cin >> n >> m;
    if(n==1 || m==1){
        cout << 1 << ' ' << 1 << endl;
        return;

    }
    if(m==3 || n==3){
        cout << 2 << ' ' << 2 << endl;
    }
    else{
        cout << 1 << ' ' << 1 << endl;
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



