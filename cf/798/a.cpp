#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
typedef long long ll;

void solve(){
    int n,m,k; cin >> n >> m >> k;
    string a,b; cin >> a >> b;
    vector<char> c;
    sort(begin(a),begin(a)+n);
    sort(begin(b),begin(b)+m);
    map<int,int> temp;
    int oka =0,okb=0;
    int usando=0;
    while(temp[1] < n && temp[2] < m){
        if(oka==k){
            c.push_back(b[temp[2]]);
            okb=0;
            oka=0;
            temp[2]++;
            usando = 2;
        }
        else if(a[temp[1]] < b[temp[2]]){
            if(usando == 2){ 
                oka=0;
                okb=0;
            }
            c.push_back(a[temp[1]]);
            temp[1]++;
            oka++;
            usando = 1;
        }
        if(okb==k){
            c.push_back(a[temp[1]]);
            okb=0;
            oka=0;
            usando = 1;
            temp[1]++;
        }
        else if(b[temp[2]] < a[temp[1]]){
            if(usando == 1){
                okb=0;
                oka=0;
            }
            c.push_back(b[temp[2]]);
            temp[2]++;
            okb++;
            usando = 2;
        }
    }
    for(auto u : c){
        if(u <= 'z' && u >= 'a')cout << u;
    }
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

