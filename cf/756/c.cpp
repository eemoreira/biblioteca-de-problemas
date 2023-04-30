#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
typedef long long ll;

const int mx = (int) 2e5 + 5;

void solve(){
    int n; cin >> n;
    deque<int> a;
    int m = INT_MIN;
    for(int i = 0 ; i < n ; i++){
        int d; cin >> d;
        a.push_back(d);
        m = max(d,m);
    }
    if(a.front()!= m && a.back()!= m){
        cout << -1 << endl;
        return;
    }
    for(int i = n-1; i>=0; i--)cout<<a[i]<<' ';
    cout << endl;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
	int tc; cin >> tc;
    while(tc--)
    solve();
	return 0;
}

