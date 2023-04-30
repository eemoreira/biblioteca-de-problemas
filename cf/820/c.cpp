#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef priority_queue<ii, vector<ii>, greater<ii>> pqg;
const int mx = 2e5 + 5;


void solve(){
    string s; cin >> s;
    int cost = (int) s[s.size()-1] - s[0];
    cost = abs(cost);
    char ma = max(s[0],s[s.size() - 1]);
    char mi = min(s[0], s[s.size()-1]);
    map<int,int> valid;
    pqg pq;
    int tam=0;
    for(int i = 0; i < s.size() ; i++) if(s[i] >= mi && s[i] <= ma){
        pq.push(ii(abs(s[i] - s[0]),i));
        tam++;
    }
    cout << cost << ' ' << tam << endl;
    while(!pq.empty()){
        cout << pq.top().second + 1 << ' ';
        pq.pop();
    }
    cout << endl;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int tc; cin >>tc;
    while(tc--){
        solve();
    }
	return 0;
}

