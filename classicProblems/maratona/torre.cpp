#include<bits/stdc++.h>

using namespace std;

const int MAX = 1000;
int n;
vector<int> move(2*MAX);
int suml[MAX];
int sumc[MAX];
int arr[MAX][MAX];

void solve(){
    cin >> n;
    int s=0;
    for(int i = 0;i < n; i++){
        for(int k = 0;k < n;k++){
            cin >> arr[i][k];
            s += arr[i][k];
        }
        suml[i] = s;
        s = 0;
    }
    for(int k = 0;k < n; k++){
        for(int i = 0;i < n;i++){
            s += arr[i][k];
        }
        sumc[k] = s;
        s = 0;
    }
    int res[MAX][MAX];
    int maior = INT_MIN;
    for(int i = 0; i < n; i++){
        for(int k = 0; k < n; k++){
        res[i][k] = suml[i] + sumc[k] - 2*arr[i][k];
        if(res[i][k] > maior) maior = res[i][k];
    }
    }
    cout << maior << endl;
}

int main(){
    ios_base::sync_with_stdio(0); 
	cin.tie(0); 
    solve();
    return 0;
}
