#include <iostream>
#include <cmath>
#include <numeric>

void solve();

using namespace std;

int main(){
    solve();
    return 0;
}

void solve(){
    string s;
    string x;
    getline(cin >> ws, s);
    getline(cin >> ws, x);
    cout << s.append(x) << endl;
    cout << s << endl;

}

//precisa de mais coisa.