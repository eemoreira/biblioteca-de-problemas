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
    unsigned long long n; cin >> n;
    unsigned long long s = 0, e = (unsigned long long) 1e18;
    unsigned long long sum;
    while(s < e){
        unsigned long long mid = s + (e-s+1)/2;
        unsigned long long d = (mid/2);
        sum = 3*d*(mid+1);
        if(sum > n) e = mid-1;
        else s = mid; 
    }
    unsigned long long dd = s/2;
    /* cout << dd << endl; */
    sum = 3*(s+1)*dd;
    cout << s << ' ' << sum << endl;
    sum += ((s+1)*2);
    /* cout << sum << endl; */
    if(n >= sum)s++;
    cout << s << endl;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int tc=1;
	if(ok2321) cin >> tc;
    while(tc--) solve();
	return 0;
}




