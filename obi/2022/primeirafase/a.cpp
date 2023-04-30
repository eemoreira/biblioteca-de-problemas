#include <bits/stdc++.h>

using namespace std;
typedef tuple<int,int,int> i3;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int d, a, n;
    cin >> d >> a >> n;
    int dias = 32 - n;
    cout << dias * (d + min(14, (n - 1)) * a) << '\n';
}





