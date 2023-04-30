#include <bits/stdc++.h>

using namespace std;
typedef tuple<int,int,int> i3;
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    int somaComzero = 0;
    int somaSemzero = 0;
    for (int i = 0; i < n; i++) {
        int agora = 0;
        int temzero = 0;
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            if (a[i][j] == 0) {
                temzero = 1;
            }
            agora += a[i][j];
        }
        if (temzero) {
            somaComzero = agora;
        }
        else {
            somaSemzero = agora;
        }
    }
    int resposta = somaSemzero - somaComzero;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] == 0) {
                cout << resposta << '\n';
                cout << i + 1 << '\n';
                cout << j + 1 << '\n';
            }
        }
    }
}





