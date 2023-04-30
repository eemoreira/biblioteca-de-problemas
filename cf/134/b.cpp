#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
typedef long long ll;

const int mx = 1e3+5;

vector<pair<int,int>> moves = {{0,1},{0,-1},{1,0},{-1,0}};
int grid[mx][mx];

void solve(){
    int n,m,lx,ly,d;
    cin>>n>>m>>lx>>ly>>d;
    int esq,dir,up,down;
    esq = ly - d;
    dir = ly + d;
    up = lx - d;
    down = lx + d;
    if(up <= 1 && down >= n || esq <= 1 && dir >= m || up <= 1 && esq <= 1 || down >= n && dir >= m){
        cout << -1 << endl;
        return;
    }

    cout << n + m -2 << endl;
    
}


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int tc; cin >> tc;
    while(tc--)
    solve();
    return 0;
}

