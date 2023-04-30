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
#define pf push_front
#define eb emplace_back

int ok2321 = 1;

void solve(){
    int n; cin >> n;
    vi a(n);
    for(auto & u : a) cin >> u;
    vector<ii> difs;
    for(int i = 1; i < n; i++){
        if(a[i] < a[i-1]) difs.eb(a[i-1]-a[i], i+1);
    }
    int cnt = 0;
    int c = 0;

    sor(difs);
    for(int i = 1; i <= n; i++){
        if(cnt == (int) difs.size()) break;
        if(i < difs[cnt].fst){
            cout << 1 << ' ';
            c++;
        }
        else{
            while(difs[cnt].fst > 0){
                cout << difs[cnt].snd << ' ';
                difs[cnt].fst -= i;
                i++;
                c++;
                if(i > n)break;
            }
            i--;
            cnt++;
        }
    }
    for(int i = c; i < n; i++) cout << 1 << ' ';
    cout << endl;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int tc=1;
	if(ok2321) cin >> tc;
    while(tc--) solve();
	return 0;
}



