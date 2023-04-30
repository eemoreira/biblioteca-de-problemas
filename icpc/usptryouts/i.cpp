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


void solve(){
    ll a,b; cin >> a >> b;
    if(b == a){
        cout << a << endl;
        return;
    }
    ll t = a;
    ll ba = 10;
    ll ans = b;
    while(1){
        ans -= ans%a;
        ans += a;
        ll cur = ans;
        ll keep = cur;
        while(cur){
            if(cur==b){
                cout << keep << endl;
                return;
            }
            cur /= 10;
        }
        ans = b*ba;
        ba *= 10;
    }
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int tc; cin >> tc;
    while(tc--) solve();
	return 0;
}



