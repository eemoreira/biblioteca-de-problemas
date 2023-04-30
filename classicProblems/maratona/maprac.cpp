#include <bits/stdc++.h>

using namespace std;

const int MAX =1e5;

int main(){
	map<int,int> freq;
	int arr[MAX];
	int n; cin >>n;
	for(int i =0;i<n;i++){
		cin >> arr[i];
	}
	for(int i = 0;i < n; i++){
		freq[arr[i]]++;
	}
	for(auto u : freq){
		cout << "freq" << u.first << ": " << u.second << endl;
	}
	cout << freq.size() << endl;
	return 0;
}
