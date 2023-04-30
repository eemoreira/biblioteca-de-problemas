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
    int n,s; cin >> n >> s;
    vi a(n);
    for(auto &u : a) cin >> u;
    int l = 0, r = n, ans = 0;
    int db = 0;
    int summ = 0;
    for(int i = 0; i < n;i++) summ += a[i];
    if(summ == s){
        cout << 0 << endl;
        return;
    }
    while(l <= r){
        int mid = (l+r)/2;
        int sum = 0;
        for(int i = 0; i < mid; i++) sum += a[i];
        int ok = 0;
        int ress = 1e9;
        /* cout << "mid: " << mid << " sum: " << sum << endl; */
        for(int i = 0; i < mid; i++){
            ress = summ - sum;
            /* cout << "ress: " << ress << endl; */
            if(ress <= s){
                ok = 1;
                break;
            }
            /* cerr << mid-i-1  << ' ' << n-i-1 << endl; */
            sum -= a[mid-i-1];
            sum += a[n-1-i];
        }
        ress = summ  - sum;
        if(ok || ress <= s){
            r = mid - 1;
            if(ress == s) ans = mid, db = 1,ok=1;
        }
        else l = mid + 1;
    }
    cout << (db ? ans : -1) << endl;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int tc=1;
	if(ok2321) cin >> tc;
    while(tc--) solve();
	return 0;
}



