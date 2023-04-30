#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;

void solve(){
    int n; cin >> n;
    vector<ii> a;
    for(int i = 0; i < n; i++){
        int am; cin >> am;
        a.push_back({am,i+1});
    }
    sort(a.begin(),a.end(),greater<ii>());
    cout << a[0].second << endl;

}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int tc; cin >> tc;
    while(tc--)
    solve();
	return 0;
}

