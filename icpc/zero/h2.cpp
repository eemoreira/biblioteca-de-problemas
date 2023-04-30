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
    unsigned long long s = 0, e = 1e18;
    unsigned long long sum=0;
    while(s < e){
        unsigned long long mid = s + (e-s+1)/2;
        unsigned long long d;
        if(mid&1) d=(mid+1)/2, sum = 3*d*mid;
        else d=mid/2, sum = 3*d*(mid+1);
        /* cout << mid << endl; */
        if(sum > n) e = mid-1;
        else s = mid; 
    }
    unsigned long long dd;
    /* cout << s << ' ' << e << endl; */
    /* cout << s << ' ' << sum << endl; */
    if(s&1) dd = (s+1)/2, sum = 3*dd*s;
    else dd = s/2, sum = 3*dd*(s+1);
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




